#include<stdio.h>
#include<stdlib.h>
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

int main()
{
	BTree *T;
	T=(BTree *)Create_Tree();
	int key;
	int choice;
	printf("Creation of B tree for node %d\n",M);
	while(1)
	{
		printf("\n\n\t\t1.Insert\n");
		printf("\t\t2.Delete\n");
		printf("\t\t3.Search\n");
		printf("\t\t4.Display\n");
		printf("\t\t5.Quit\n");
		printf("\t\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				//printf("Enter the key : ");
				//scanf("%d",&key);
				for(key=1;key<=50;key++)
				insert(T,key);
				display(T->root,0);
				break;
			case 2:
				printf("Enter the key : ");
				scanf("%d",&key);
				DelNode(T,key);
				break;
			case 3:
				printf("Enter the key : ");
				scanf("%d",&key);
				search(T,key);
				break;
			case 4:
				printf("Btree is :\n");
				display(T->root,0);
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
