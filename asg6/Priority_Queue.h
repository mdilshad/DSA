int Parent(int i)
{
	return i/2;
}
int Left(int i)
{
	return 2*i;
}
int Right(int i)
{
	return 2*i+1;
}
void Min_Heapify(struct vertex **Q,int i,int size)
{
	int l,r,small;
	struct vertex *temp;
	l=Left(i);
	r=Right(i);
	if(l<=size && Q[l-1]->key < Q[i-1]->key)
		small=l;
	else
		small=i;
	if(r<=size && Q[r-1]->key < Q[small-1]->key)
		small=r;
	if(i!=small)
	{
		temp=Q[small-1];
		Q[small-1]=Q[i-1];
		Q[i-1]=temp;
		Min_Heapify(Q,small,size);
	}		
}
void Build_Min_Heap(struct vertex **Q,int n)
{
	int i;
	for(i=n/2;i>0;i--)
		Min_Heapify(Q,i,n);
}
struct vertex * extract_min(struct vertex **Q,int n)
{
	Build_Min_Heap(Q,n);
	struct vertex *min;
	min=Q[0];
	Q[0]=Q[n-1];
	return min;
}
void Decrease_Key(struct vertex **Q,int i,int key)
{
	struct vertex *temp;
	Q[i-1]->key=key;
	for(;i>1 && Q[i-1]->key < Q[Parent(i)-1]->key;i=Parent(i))
	{
		temp=Q[i-1];
		Q[i-1]=Q[Parent(i)-1];
		Q[Parent(i)-1]=temp;
	}
}
void Insert_Key(struct vertex **Q,struct vertex *vrtx,int n)
{
	Q[n-1]=vrtx;
	Decrease_Key(Q,n,Q[n-1]->key);
}
int Find_Vertex(struct vertex **Q,struct vertex *vrtx,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(Q[i]==vrtx)
			return 1;
	return 0;
}
