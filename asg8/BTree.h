#define M 5
typedef struct node
{
	int n; 
	int keys[M-1];
	struct node *p[M];
}Node;

typedef struct BTREE
{
	Node *root;
}BTree;
enum KeyStatus { Duplicate,SearchFailure,Success,InsertIt,LessKeys };
int searchPos(int ,int *, int);
enum KeyStatus ins(Node *, int, int*, Node**);
void insert(BTree *,int);
void display(Node *,int);
enum KeyStatus del(BTree *,Node *, int);
void DelNode(BTree *,int);
void search(BTree *,int);
BTree * Create_Tree();
