#include<stdio.h>
#include<stdlib.h>
#include"node.c"

int main(){
	struct node *list1[30];
	int nodeval=-1, i=0;
	printf("Type number you wish to insert into list (-1 to exit):");
	scanf("%d",&nodeval);
	while(1)
	{
		list1[i]= (struct node*) malloc(sizeof(struct node));
		list1[i]->value=nodeval;
		if(i>0)
		{
			list1[i-1]->next=list1[i];
			list1[i]->prev=list1[i-1];
		}
		i++;
		if(i==30)
		{
			break;
		}
		scanf("%d",&nodeval);
		if(nodeval==-1)
		{
			break;
		}
	}
	i--;
	//printf("\n\n%d\n\n", list1[1]->prev->value);
	printf("Original List:\n");
	printsort(list1[0], i);
	bubblesort(list1[0], i);
	printf("\nSuccesful sort\n");
	printsort(list1[0], i);
}


