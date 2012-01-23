#include<stdlib.h>
typedef struct node
{
	char data[50];
	struct node *next;
}Node;
void InsertLL(Node **head,Node *x)
{
	x->next = *head;
	*head = x;
}
void DeleteLL(Node **head,Node *x)
{
	Node *y;
	if(*head == x)
		*head = x->next;
	else
	{
		y = *head;
		while(y->next != x)
			y = y->next;
		y->next = x->next;
	}
	free(x);
}
