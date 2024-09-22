#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>
#define clear() printf("\033[H\033[J")
#define MAXLINE 4096
#define LIST 100

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap) {
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));
    strcat(buf, "\n");
    fflush(stdout);    /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);      /* flushes all stdio output streams */
}

void inShell()
{
	char *name=getenv("USER");; //Display User apon shell startup
	clear();
	printf("@%s",name);
	clear();
}

int userInput(char* strIn)
{
	char* line; 
	line=readline("\n");//read line and copy to line.
	if(strlen(line)!=0)
	{
		strcpy(strIn,line); //if a line exist, copy it to inputted string
		add_history(line); //set point in history
		return(0); //return 0 implies it succeeds
	}
	return(1); //return 1 since it failed
}

void printDir()
{
	char cwd[1024]; //max size of cwd
	getcwd(cwd,sizeof(cwd));
	printf("\nDir: %s",cwd); //print the diretory
}

void sysExec(char** prse)
{
	pid_t pid =fork(); //form a fork
	if(pid==-1)
	{
		printf("Fork failure\n"); //test to see if fork fails
		return;
	}
	else if (pid==0)
	{ //Do this if fork succeed.
		if(execvp(prse[0],prse)<0)//trying to execute command
		{
			printf("Command execution failure\n");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}

void execPipe(char** parsed, char**piped)
{
	int pipeTest[2]; //execute pipe.
	pid_t pipe1, pipe2;

	if(pipe(pipeTest)<0)
	{
		printf("Pipe not initialized");
		return;
	}
	if (pipe1==0)
	{
		close(pipeTest[0]);
		dup2(pipeTest[1], STDOUT_FILENO);
		close(pipeTest[1]);
		if (execvp(parsed[0],parsed) <0)
		{
			printf("First pipe failed");
			exit(0);
		}
	}
	else
	{
		pipe2=fork();
		if(pipe2<0)
		{
			printf("Could not fork");
			return;
		}
		if(pipe2==0)
		{
			close(pipeTest[1]);
			dup2(pipeTest[0], STDIN_FILENO);
			close(pipeTest[0]);
			if (execvp(piped[0], piped)<0)
			{
				printf("Second Pipe failed");
				exit(0);
			}
		}
		else
		{
		wait(NULL);
		}
	}
}

int cmdHandler(char** parsed)
{
	int num=3,arg=0;
	char* name;
	char* List[num];

	List[0]="exit";
	List[1]="cd";
	List[2]="username";
	for(int i =0; i<num; i++)
	{
		if(strcmp(parsed[0],List[i])==0)
		{
			arg=i+1;
			break;
		}
	}
	if(arg==1)
	{
		printf("Exit command\n");
		exit(0);
	}
	else if(arg==2)
	{
		chdir(parsed[1]); //changes directory
		return 1;
	}
	else if(arg==3)
	{
		name=getenv("USER");
		printf("Hello %s\n",name);
		return 1;
	}
	return 0;
}

int parsePipe(char* str, char**strpipe)
{
	for(int i =0; i<2; i++)
	{
		strpipe[i]=strsep(&str,"|");
		if (strpipe[i]==NULL)
		{
			break;
		}
	}
	if(strpipe[1]==NULL)
	{
		return 0;
	}
	return 1;
}

void parseS(char* str, char** parsed)
{
	for(int i=0;i<LIST;i++)
	{
		parsed[i]=strsep(&str," ");
		if(parsed[i]==NULL)
		{
			break;
		}
		if(strlen(parsed[i])==0)
		{
			i--;
		}
	}
}

int processing(char* str, char** parsed, char** parpipe)
{
	char* strpipe[2];
	int biped=0;
	biped=parsePipe(str,strpipe);
	if(biped)
	{
		parseS(strpipe[0],parsed);
		parseS(strpipe[1],parpipe);
	}
	else
	{
		parseS(str, parsed);
	}
	if(cmdHandler(parsed))
	{
	return 0;
	}
	return 1+biped;
}


int main(void) {
    	char   inString[MAXLINE], *argsParsed[LIST];
	char* parsedPiped[LIST];
	inShell();
  	int flag=0;
	printf("%% ");  /* print prompt (printf requires %% to print %) */
    	while (1)
	{
        	printDir();
		if(userInput(inString))
		{
			continue;
		}
		flag=processing(inString, argsParsed, parsedPiped);
		if(flag==1)
		{
			sysExec(argsParsed);
		}
		if(flag==2)
		{
			execPipe(argsParsed,parsedPiped);
		}
	}
	return 0;
}

