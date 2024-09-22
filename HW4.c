#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void swap(char**a, char**b){ //take to character inputs
    char*c=*a; //set a temporary value to hold one
    *a=*b;
    *b=c; //swap them
}

void sort(char *mem, int num){

    char* lowest; //declare a variable to keep track of Lowest character according to ASCII.
    for(int i=0;i<=num;i++){
        *lowest=*(mem+i);
        for (int j=i; j<=num; j++){ //Run a sort function that iterates over each character.
            if(*lowest<*(mem+j)){
                printf("here\n");
                *lowest=*(mem+j);
            }

        }

        swap(*lowest, *(mem+i));//input the smallest character into the swap function and swap it with the i-th value
    }
}

int main() {

    char* mem;
    int num;
    printf("How many letters do you wish to enter: ");
    scanf("%d",&num); //Assign an inputed number to a integer to reference as the size of our array.
    printf("\nEnter sentence with %d characters: ", num);
    num++;
    mem=(char*)malloc(num*sizeof(char)); //Need to allocate memory using malloc, calloc, or realloc
    free(mem); //Should free up space since C doesn't collect trash.
    scanf("%s",mem); //have the user enter a string of characters limited in size by then number inputed.
    printf("test");

    for(int i=0; i<=num; i++){
        if(isalpha(*(mem+i)==0)){
            printf("TEST");
            *(mem+i)=' '; //Remove any non-letter characters.
        }
    }
    sort(mem,num); //input the size of the array and the array itself into a sort function.
    printf("Sorted List of characters: %s",mem); //Display sorted list to user.

    return 0;
}

