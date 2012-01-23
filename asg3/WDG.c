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
	int d,f,indegree,outdegree;
	struct edge *edgep;
	struct vertex *vertexp,*parent;
};
struct edge
{
	struct vertex *destin;
	int weight;
	struct edge *next;
};
int n;
/*---------------SET Structure------------------------------*/
typedef struct Element
{
	int count;
	struct vertex *nextelement;
}element;
struct set
{
	
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


int insert_edge(struct graph *G,char s,char d,int w)
{
	struct vertex *start,*end;
	start=find_vertex(G,s);
	end=find_vertex(G,d);
	(start->outdegree)++;
	(end->indegree)++;
	struct edge *temp,*node;
	node=(struct edge *)malloc(sizeof(struct edge));
	node->destin=end;
	node->next=0;
	node->weight=w;
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
void edge_delete(struct graph *G,char s,char d)
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
int vertex_delete(struct graph *G,char s)
{
	struct vertex *t,*temp1;
	struct edge *temp;
	G->count--;
	for(temp1=G->head;temp1;temp1=temp1->vertexp)
	{
		if(find_edge(G,s,temp1->name))
			edge_delete(G,s,temp1->name);
		if(find_edge(G,temp1->name,s))
			edge_delete(G,temp1->name,s);
	}
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
	free(t);
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

void free_graph(struct graph *G)
{
	struct vertex *temp;
	for(temp=G->head;temp;temp=temp->vertexp)
		vertex_delete(G,temp->name);
	free(G);
}
void Initialize_Single_source(struct graph *G,char s)
{
	struct vertex *t,*start;
	t=find_vertex(G,s);
	for(start=G->head;start;start=start->vertexp)
	{
		start->d=999999999;
		start->parent=NULL;
	}
	t->d=0;
}
void Relax(struct vertex *u,struct vertex *v,int w)
{
	if(v->d > u->d+w)
	{
		v->d=u->d+w;
		v->parent=u;
	}	
}
int Bellman_Ford(struct graph *G,int w,char s)
{
	struct vertex *u;
	struct edge *v;
	int i;
	Initialize_Single_source(G,s);
	for(i=1;i<G->count;i++)
	{
		for(u=G->head;u;u=u->vertexp)
			for(v=u->edgep;v;v=v->next)
				Relax(u,v->destin,v->weight);
	}
	for(u=G->head;u;u=u->vertexp)
		for(v=u->edgep;v;v=v->next)
			if(v->destin->d > u->d+v->weight)
				return 0;
	return 1;
}

void vertex(struct graph *G)
{
	struct vertex *temp;
	printf("\n");
	for(temp=G->head;temp;temp=temp->vertexp)
		printf("\t%15c%10d",temp->name,temp->d);
}
void print_path(struct graph *G)
{
	struct vertex *temp,*start;
	char S[G->count];
	int top=0;
	printf("\n\t\tAll vertex path are :");
	for(temp=G->head;temp;temp=temp->vertexp)
	{
		top=0;
		if(temp->parent==NULL&&temp->d!=0)
			continue;
		for(start=temp;start;start=start->parent)
			S[top++]=start->name;
		printf("\n\t\t");
		while(top--)
			printf("%c->",S[top]);
	}
}
void heapify(struct vertex **Q,int i,int size)
{
	int l,r,small;
	struct vertex *temp;
	l=2*i;
	r=2*i+1;
	if(l<=size && Q[l-1]->d < Q[i-1]->d)
		small=l;
	else
		small=i;
	if(r<=size && Q[r-1]->d < Q[small-1]->d)
		small=r;
	if(i!=small)
	{
		temp=Q[small-1];
		Q[small-1]=Q[i-1];
		Q[i-1]=temp;
		heapify(Q,small,size);
	}		
}
void build_heap(struct vertex **Q,int n)
{
	int i;
	for(i=n/2;i>0;i--)
		heapify(Q,i,n);
}
struct vertex * extract_min(struct vertex **Q)
{
	int i;
	build_heap(Q,n);
	struct vertex *min;
		min=Q[0];
		Q[0]=Q[n-1];
		n--;
		return min;
}
void Dijkstra(struct graph *G,char s)
{
	struct vertex *Q[G->count],*S[G->count],*u,*v;
	struct edge *e;
	int i=0;
	n=G->count;
	Initialize_Single_source(G,s);
	for(v=G->head;v;v=v->vertexp,i++)
		Q[i]=v;
	i=0;
	while(n!=0)
	{
		u=extract_min(Q);
		S[i++]=u;
		for(e=u->edgep;e;e=e->next)
			Relax(u,e->destin,e->weight);
	}
}
