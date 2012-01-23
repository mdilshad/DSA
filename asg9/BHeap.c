#include<stdlib.h>
#include<stdio.h>
#include"BHeap.h"
Heap *Make_Binomial_Heap()
{
	Heap *H = malloc(sizeof(Heap));
	H->head = NULL;
	return H;
}
Node * Binomial_Heap_Minimum(Heap *H)
{
	Node *x,*y=NULL;
	int min=9999999;
	x=H->head;
	while(x!=NULL)
	{
		if(x->key < min)
		{
			min=x->key;
			y=x;
		}
		x = x->sibling;
	}
	return y;
}
void Binomial_Link(Node *y,Node *z)
{
	y->p = z;
	y->sibling = z->child;
	z->child = y;
	z->degree = z->degree + 1;
}
Node *Binomial_Heap_Merge(Heap *H1,Heap *H2)
{
	Heap *H=Make_Binomial_Heap();
	Node *x,*y,**z;
	x=H1->head;
	y=H2->head;
	z=&H->head;
	while(x || y)
	{
		if(x && (y == NULL || (x->degree <= y->degree)))
		{
			*z = x;
			x = x->sibling;
		}
		else
		{
			*z = y;
			y = y->sibling;
		}
		z = &(*z)->sibling;
	}
	return H->head;
}
Heap *Binomial_Heap_Union(Heap *H1,Heap *H2)
{
	Node *x,*prev_x,*next_x;
	Heap *H = Make_Binomial_Heap();
	H->head = Binomial_Heap_Merge(H1,H2);
	free(H1);
	free(H2);
	if(H->head == NULL)
		return H;
	prev_x = NULL;
	x = H->head;
	next_x = x->sibling;
	while(next_x != NULL)
	{
		if((x->degree != next_x->degree) || (next_x->sibling != NULL && (next_x->sibling->degree == next_x->degree)))
		{
			prev_x = x;
			x = next_x;
		}
		else // two adjacent node with same degree
		{
			if(x->key <= next_x->key)
			{
				x->sibling = next_x->sibling;
				Binomial_Link(next_x,x);
			}
			else
			{
				if(prev_x == NULL)
					H->head = next_x;
				else
					prev_x->sibling = next_x;
				Binomial_Link(x,next_x);
				x = next_x;
			}
		}
		next_x = x->sibling;
	}
	return H;
}
void Binomial_Heap_Insert(Heap **H,Node *x)
{
	Heap *H1 = Make_Binomial_Heap();
	x->p = NULL;
	x->child = NULL;
	x->sibling = NULL;
	x->degree = 0;
	H1->head = x;
	*H = Binomial_Heap_Union(*H,H1);
}
Node *Link_List_Reverse(Node *x)
{
	if(x == NULL)
		return x;
	Node *y,*z;
	y = x->sibling;
	x->sibling = NULL;
	while(y != NULL)
	{
		z = y->sibling;
		y->sibling = x;
		x = y;
		y = z;
	}
	return x;
}
Node *Binomial_Heap_Extract_Min(Heap **H)
{
	if((*H)->head == NULL)
		return NULL;
	Node *x,*y = NULL;
	Heap *H1;
	x = Binomial_Heap_Minimum(*H);
	y = (*H)->head;
	if(y == x)
		(*H)->head = x->sibling;
	else
	{
		while(y && y->sibling != x)
			y = y->sibling;
		y->sibling = x->sibling; 
	}
	y = Link_List_Reverse(x->child);
	H1 = Make_Binomial_Heap();
	H1->head = y;
	*H = Binomial_Heap_Union(*H,H1);
	return x;
}
void Binomial_Heap_Decrease_Key(Heap *H,Node *x,int k)
{
	int temp;
	if(k > x->key)
		return;
	x->key = k;
	while(x->p != NULL && x->key < x->p->key)
	{
		temp = x->key;
		x->key = x->p->key;
		x->p->key = temp;
		x = x->p;
	}
}
Node *Inorder(Node *x,int key)
{
	if(x == NULL)
		return NULL;
	if(key == x->key)
		return x;
	Node *y,*z;
	y = Inorder(x->child,key);
	z = Inorder(x->sibling,key);
	return y?y:z;
}
Node *Binomial_Heap_Search(Heap *H,int key)
{
	Node *x,*y;
	x = H->head;
	while(x != NULL)
	{
		if(key == x->key)
			return x;
		else if(key > x->key)
		{
			y = Inorder(x->child,key);
			if(y)
				return y;
		}
		x = x->sibling;
	}
}
void Binomial_Heap_Delete(Heap **H,Node *x)
{
	Binomial_Heap_Decrease_Key(*H,x,-9999999);
	Binomial_Heap_Extract_Min(H);
}
void print(Heap *H)
{
	Node *x = H->head;
	while(x != NULL)
	{
		printf("\t%d",x->key);
		x = x->sibling;
	}
}
