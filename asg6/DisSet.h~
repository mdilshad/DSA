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
