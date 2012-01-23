#include<stdlib.h>
#include<stdio.h>
#include"Graph.h"
#include"Priority_Queue.h"
#include"DisSet.h"
#include"Heap_Sort.h"
void show_edge(struct vertex *G,int size)
{
	struct edge *temp;
	int i=0;
	for(;i<size;i++)
	{
		printf("\n%d->",i+1);
		for(temp=G[i].edgep;temp;temp=temp->next)
			printf("%d,",temp->destin+1);
	}
}
void vertex_detail(struct vertex *G,int size)
{
	int i=0;
	printf("\n\tvertex\tKey");
	for(;i<size;i++)
		printf("\n\t%d.   %5d",i+1,G[i].key);	
}
void Prim(struct vertex *G,int r,int n)
{
	struct vertex *Q[n],*u;
	struct edge *e;
	int i;
	for(i=0;i<n;i++)
	{
		G[i].key=99999;
		G[i].p=0;
	}
	G[r-1].key=0;
	for(i=0;i<n;i++)
		Insert_Key(Q,&G[i],i+1);
	i=n;
	while(i!=0)
	{
		u=extract_min(Q,i);
		i--;
		for(e=u->edgep;e;e=e->next)
			if(Find_Vertex(Q,&G[e->destin],i)&&(e->weight < G[e->destin].key))
			{
				G[e->destin].key=e->weight;
			}
	}
	vertex_detail(G,n);
}
void Vertex_Detail_Prim(struct edge **A,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\n%d.\t%d----->%d",i+1,A[i]->start+1,A[i]->destin+1);
}
void MST_Kruskal(struct vertex *G,int n,int E)
{
	int i,j;
        struct edge *A[n-1],*temp,*e[E];
        for(i=0;i<n;i++)
                Make_Set(G,i);
       for(i=0,j=0;i<n;i++)
		for(temp=G[i].edgep;temp;temp=temp->next)
			e[j++]=temp;
        Heap_Sort(e,E);
        for(i=0,j=0;i<E;i++)
    		if(Find_Set(G,e[i]->start)!=Find_Set(G,e[i]->destin))
       		{
       			A[j++]=e[i];
        		Union(G,e[i]->start,e[i]->destin);
        	}
        Vertex_Detail_Prim(A,j);
}
