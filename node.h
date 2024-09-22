#define NODE_H

#include<stdio.h>

struct node{
	int value;
	struct node *next;
	struct node *prev;
};
void bubblesort (struct node *list1, int length);

void printlist (struct node *list1, int length);

