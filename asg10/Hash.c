#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define M 10
typedef struct node
{
	char data[50];
	struct node *next;
}Node;

int Hash(char *str)
{
	int i=0;
	while(*str)
	{
		i += (int)*str;
		str++;
	}
	return i%M;
}

void Insert(Node **T,char *str)
{
	int k;
	Node *x;
	k=Hash(str);
	x = malloc(sizeof(Node));
	strcpy(x->data,str);
	InsertLL(&T[k],x);
}
Node *Search(Node **T,char *str)
{
	int k;
	Node *x;
	k=Hash(str);
	x = T[k];
	while(x != NULL && strcmp(x->data,str))
		x = x->next;
	return x;
}
int Delete(Node **T,char *str)
{
	Node *x = Search(T,str);
	if(x)
	{
		int k;
		k=Hash(str);
		DeleteLL(&T[k],x);
		return 1;
	}
	return 0;
}
