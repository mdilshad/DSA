#include<stdlib.h>
#include<stdio.h>
struct graph
{
	int count;
	struct vertex *head;
};
enum chrom{white,grey,black};
struct vertex
{
	char name;
	enum chrom color;
	int indegree,outdegree,distance;
	struct edge *edgep;
	struct vertex *vertexp,*parent;
};
struct edge
{
	struct vertex *destin;
	struct edge *next;
};
struct graph *create_graph(struct graph *G)
{
	G=(struct graph *)malloc(sizeof(struct graph));
	G->count=0;
	G->head=0;
	return G;
}
int insert_vertex(struct graph *G,char info)
{
	struct vertex *node,*temp;
	node=(struct vertex *)malloc(sizeof(struct vertex));
	if(G->head==0)
		G->head=node;
	else
	{
		for(temp=G->head;temp->vertexp;temp=temp->vertexp);
			temp->vertexp=node;
	}
	node->name=info;
	node->indegree=node->outdegree=0;
	node->edgep=0;
	node->vertexp=0;
	node->color=white;
	node->parent=0;
	G->count++;
}
struct vertex * find_vertex(struct graph *G, char v)
{
	struct vertex *temp;
	for(temp=G->head;temp;temp=temp->vertexp)
		if(temp->name==v)
			return temp;
	return 0;
}
int insert_edge(struct graph *G,char s,char d)
{
	struct vertex *start,*end;
	start=find_vertex(G,s);
	if(!start)
		return 0;
	end=find_vertex(G,d);
	if(!end)
		return 0;
	(start->outdegree)++;
	(end->indegree)++;
	struct edge *temp,*node;
	node=(struct edge *)malloc(sizeof(struct edge));
	node->destin=end;
	node->next=0;
	if(start->edgep==0)
		start->edgep=node;
	else
	{
		for(temp=start->edgep;temp->next;temp=temp->next);
			temp->next=node;
	}
	return 1;
}
int find_edge(struct graph *G,char s,char d)
{
	struct vertex *t;
	struct edge *temp;
	t=find_vertex(G,s);
	if(!t)
		return 0;
	for(temp=t->edgep;temp&&temp->destin->name!=d;temp=temp->next);
		if(temp)
			return 1;
	return 0;	 
}
int edge_delete(struct graph *G,char s,char d)
{
	if(find_edge(G,s,d))
	{
		struct vertex *start,*end;
		struct edge *temp,*node;
		start=find_vertex(G,s);
		end=find_vertex(G,d);
		(start->outdegree)--;
		(end->indegree)--;
		if(start->edgep->destin==end)
		{
			node=start->edgep;
			start->edgep=start->edgep->next;
			free(node);
		}
		else
		{
			for(temp=start->edgep;temp->next->destin!=end;temp=temp->next);
			node=temp->next;
			temp->next=temp->next->next;
			free(node);
		}
	}
}
int vertex_delete(struct graph *G,char s)
{
	struct vertex *t,*temp1;
	struct edge *temp;char e;
	G->count--;
	if(G->head->name==s)
	{
		t=G->head;
		G->head=G->head->vertexp;
	}
	else
	{
		for(temp1=G->head;temp1->vertexp->name!=s;temp1=temp1->vertexp);
		t=temp1->vertexp;
		temp1->vertexp=t->vertexp;
	}
	for(temp=t->edgep;temp;temp=temp->next)
	{
		edge_delete(G,s,temp->destin->name);
		edge_delete(G,temp->destin->name,s);
	}
	free(t);
}
void matrix_rep(struct graph *G)
{
	struct vertex *t,*p;
	struct edge *temp;
	int n;
	printf("\t");
	for(t=G->head;t;t=t->vertexp)
	printf("\t%c",t->name);
	for(t=G->head;t;t=t->vertexp)
	{	
		printf("\n\t%c",t->name);
		for(p=G->head;p;p=p->vertexp)
		 	 printf("\t%d",find_edge(G,t->name,p->name));
	}	
}
void show_edge(struct graph *G)
{
	struct vertex *t;
	struct edge *temp;
	for(t=G->head;t;t=t->vertexp)
	{
		printf("\n%c->",t->name);
		for(temp=t->edgep;temp;temp=temp->next)
			printf("%c,",temp->destin->name);
	}
}
void BFS(struct graph *G,char s,int p)
{
	struct vertex *start=find_vertex(G,s),*t;
	struct edge *temp;
	char Q[G->count];
	int front=-1,rear=-1,i;
	for(t=G->head;t;t=t->vertexp)
	{
		t->color=white;
		t->distance=-1;
		t->parent=NULL;
	}
	start->color=grey;
	start->distance=0;
	start->parent=NULL;
	Q[++rear]=s;
	while(front!=rear)
	{
		s=Q[++front];
		start=find_vertex(G,s);
		for(temp=start->edgep;temp;temp=temp->next)
			if(temp->destin->color==white)
			{
				temp->destin->color==grey;
				Q[++rear]=temp->destin->name;
				temp->destin->distance=start->distance+1;
				temp->destin->parent=start;
			}
			start->color=black;
			if(p)
				printf("*%c->",start->name);
	}	
}
void DFS_visit(struct graph *G,char u,int time)
{
	struct vertex *start=find_vertex(G,u),*t;
	struct edge *temp;
	start->color=grey;
	time++;
	start->distance=time;
	for(temp=start->edgep;temp;temp=temp->next)
		if(temp->destin->color==white)
		{
			temp->destin->parent=start;
			DFS_visit(G,temp->destin->name,time);
		}
	start->color=black;
	printf("%c->",start->name);
	//time=time+1;
}
void DFS(struct graph *G)
{
	struct vertex *t;
	int time=0;
	for(t=G->head;t;t=t->vertexp)
	{
		t->color=white;
		t->parent=NULL;
	}
	for(t=G->head;t;t=t->vertexp)
	{
		if(t->color==white)
			DFS_visit(G,t->name,time);
	}
}
void vertex_detail(struct graph *G,char v)
{
	struct edge *t;
	struct vertex *temp=find_vertex(G,v);
	printf(" Name  %15c\n Distance %15d\n Parent %15c \n Adjacent vertices",temp->name,temp->distance,temp->parent!=0?temp->parent->name:0);
	for(t=temp->edgep;t;t=t->next)
		printf("\t%c",t->destin->name);
}
void print_path(struct graph *G,char s,char v)
{
	struct vertex *temp=find_vertex(G,v);
	if(v==s)
		printf("%c",s);
	else if(temp->parent==NULL)
		printf("\t\tNo path Exists from %c to %c\n",s,v);
	else 
		print_path(G,s,temp->parent->name);
	printf("%c",v);
}
int distance(struct graph *G,char s,char v)
{
	struct vertex *temp=find_vertex(G,v);
	BFS(G,s,0);
		return temp->distance;	
}
void free_graph(struct graph *G)
{
	struct vertex *temp;
	for(temp=G->head;temp;temp=temp->vertexp)
	vertex_delete(G,temp->name);
	free(G);
}
