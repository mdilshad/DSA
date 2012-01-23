void Max_Heapify(struct edge **E,int i,int size)
{
	int l,r,largest;
	struct edge *temp;
	l=Left(i);
	r=Right(i);
	if(l<=size && E[l-1]->weight > E[i-1]->weight)
		largest=l;
	else
		largest=i;
	if(r<=size && E[r-1]->weight > E[largest-1]->weight)
		largest=r;
	if(i!=largest)
	{
		temp=E[largest-1];
		E[largest-1]=E[i-1];
		E[i-1]=temp;
		Max_Heapify(E,largest,size);
	}		
}
void Build_Max_Heap(struct edge **E,int n)
{
	int i;
	for(i=n/2;i>0;i--)
		Max_Heapify(E,i,n);
}
void Heap_Sort(struct edge **E,int n)
{
	int i,j;
	Build_Max_Heap(E,n);
	struct edge *temp;
	for(i=n;i>1;i--)
	{
		temp=E[i-1];
		E[i-1]=E[0];
		E[0]=temp;
		Max_Heapify(E,1,i-1);
	}
}
