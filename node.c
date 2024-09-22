#include<stdio.h>
#include"node.h"

void bubblesort(struct node *list1, int length)
{
	int temp;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<(length-i);j++)
		{
			if(list1->value > list1->next->value) //swap the values of the nodes until the largest { //value is in the right most node by swapping if the next node is found to be //smaller then current node.
			{
				temp=list1->value;
				list1->value=list1->next->value;
				list1->next->value=temp;
			}
			list1=list1->next;//go to the next node so it can be compared
		}

		for(int k=0;k<(length-i);k++)
		{
			list1=list1->prev; //use the loop to reset back to the first node
		}
	}
}

void printsort(struct node *list1, int length)
{

	int rec=0;
	while(rec<(length))
	{
		printf("%d <==> ", list1->value);
		list1=list1->next;
		rec++;
	}
	printf("%d\n",list1->value);
	for(int j=0;j<(length);j++)
	{
		list1=list1->prev; //use the loop to reset back to the first node
	}

}
