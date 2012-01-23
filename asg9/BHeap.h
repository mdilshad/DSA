typedef struct node
{
	int key,degree;
	struct node *p,*child,*sibling;
}Node;

typedef struct heap
{
	Node *head;
}Heap;
Heap *Make_Binomial_Heap();
Node * Binomial_Heap_Minimum(Heap *);
void Binomial_Link(Node *y,Node *);
Node *Binomial_Heap_Merge(Heap *,Heap *);
Heap *Binomial_Heap_Union(Heap *,Heap *);
void Binomial_Heap_Insert(Heap **,Node *);
Node *Link_List_Reverse(Node *);
Node *Binomial_Heap_Extract_Min(Heap **);
void Binomial_Heap_Decrease_Key(Heap *,Node *,int);
Node *Inorder(Node *x,int);
Node *Binomial_Heap_Search(Heap *,int);
void Binomial_Heap_Delete(Heap **,Node *);
void print(Heap *);
