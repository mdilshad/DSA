#include<stdlib.h>
#include<stdio.h>
enum chrom{white,black};
struct vertex
{
	int rank,p,root;
	enum chrom color;
	struct edge *edgep;
};
struct edge
{
	int destin;
	struct edge *next;
};
void Initialize(struct vertex *G,int size)
{
	int i;
	for(i=0;i<size;i++)
		G[i].edgep=0;
}
int insert_edge(struct vertex *G,int s,int d)
{
	struct edge *temp,*node;
	node=(struct edge *)malloc(sizeof(struct edge));
	node->destin=d;
	node->next=0;
	if(G[s].edgep==0)
		G[s].edgep=node;
	else
	{
		for(temp=G[s].edgep;temp->next;temp=temp->next);
		temp->next=node;
	}
	return 1;
}
int find_edge(struct vertex *G,int s,int d)
{
	struct edge *temp;
	for(temp=G[s].edgep;temp&&temp->destin!=d;temp=temp->next);
	if(temp)
		return 1;
	return 0;	 
}
void edge_delete(struct vertex *G,int s,int d)
{
	struct edge *temp,*node;
	if(G[s].edgep->destin==d)
	{
		node=G[s].edgep;
		G[s].edgep=G[s].edgep->next;
		free(node);
	}
	else
	{
		for(temp=G[s].edgep;temp->next->destin!=d;temp=temp->next);
		node=temp->next;
		temp->next=temp->next->next;
		free(node);
	}
}
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
void Make_Set(struct vertex *G,int i)
{
	G[i].p=i;
	G[i].rank=0;
	G[i].root=i;
}
int Find_Set(struct vertex *G,int i)
{
	if(G[i].p!=i)
	{
		G[i].p=Find_Set(G,G[i].p);
		G[i].root=G[i].p;
	}	
	return G[i].p;
}
void Union(struct vertex *G,int x, int y)
{
	int xroot,yroot;
	xroot=Find_Set(G,x);
	yroot=Find_Set(G,y);
	if(xroot!=yroot)
	{
		if(G[xroot].rank < G[yroot].rank)
			G[xroot].p=G[x].root=G[x].root=yroot;
		else
		{
			G[yroot].p=G[y].root=G[y].root=xroot;
			if(G[xroot].rank==G[yroot].rank)
				G[xroot].rank++;
		}
	}
}
void Connected_Component(struct vertex *G,int size)
{
	int i;
	struct edge *temp;
	for(i=0;i<size;i++)
		Make_Set(G,i);
	for(i=0;i<size;i++)
		for(temp=G[i].edgep;temp;temp=temp->next)
			Union(G,i,temp->destin);
}
void vertex_detail(struct vertex *G,int size)
{
	int i=0;
	printf("\n\tvertex\tRank\tParent\tRoot");
	for(;i<size;i++)
		printf("\n\t%d\t%d\t%d\t%d",i+1,G[i].rank,G[i].p+1,G[i].root+1);	
}
