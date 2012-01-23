enum chrom{white,black};
struct vertex
{
	int rank,p,root,key;
	struct vertex *perent;
	enum chrom color;
	struct edge *edgep;
};
struct edge
{
	int start,destin,weight;
	struct edge *next;
};
void Initialize(struct vertex *G,int size)
{
	int i;
	for(i=0;i<size;i++)
		G[i].edgep=0;
}
int insert_edge(struct vertex *G,int s,int d,int w)
{
	struct edge *temp,*node;
	node=(struct edge *)malloc(sizeof(struct edge));
	node->start=s;
	node->destin=d;
	node->next=0;
	node->weight=w;
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
