#include<stdio.h>
int parent(int i)
{
	return i/2;
}
int right(int i)
{
	return 2*i+1;
}
int left(int i)
{
	return 2*i;
}
void heapify(int *A,int i,int size)
{
	int l,r,large,temp;
	l=left(i);
	r=right(i);
	if(l<=size && A[l-1]>A[i-1])
		large=l;
	else
		large=i;
	if(r<=size && A[r-1]>A[large-1])
		large=r;
	if(i!=large)
	{
		temp=A[large-1];
		A[large-1]=A[i-1];
		A[i-1]=temp;
		heapify(A,large,size);
	}		
}
void build_heap(int *A,int n)
{
	int i;
	for(i=n/2;i>0;i--)
		heapify(A,i,n);
}
void heap_sort(int *A,int n)
{
	int size,temp;
	build_heap(A,n);
	for(size=n-1;size>0;size--)
	{
		temp=A[0];
		A[0]=A[size];
		A[size]=temp;
		heapify(A,1,size);
	}
}
void show(int *A,int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("\n%5d",A[i-1]);
}
int heap_extract_max(int *A,int *n)
{
	int max;
	if(*n<1)
		printf("Heap Underflow");
	else
	{
		max=A[0];
		A[0]=A[*n-1];
		(*n)--;
		heapify(A,1,*n);
		return max;
	}
}
int maximum(int *A)
{
	return A[0];
}
void heap_insert(int *A,int key,int *n)
{
	int i,x;
	(*n)++;
	for(i=*n;i>1 && A[parent(i)-1]<key;i/=2)
		A[i-1]=A[parent(i)-1];
	A[i-1]=key;
}
void increase_key(int *A,int i,int key)
{
	int temp;
	if(key < A[i-1])
		printf("Number is less then key\n");
	else
	{
		for(A[i-1]=key;i>1 && A[parent(i)-1]<A[i-1];i/=2)
		{
			temp=A[i-1];
			A[i-1]=A[parent(i)-1];
			A[parent(i)-1]=temp;
		}
	}
}
