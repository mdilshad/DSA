#include<stdio.h>
#include<stdlib.h>
enum colour{red,black};
typedef struct rbt
{
	int key;
	struct rbt *left,*right,*p;
	enum colour color;
}RBT;
typedef struct root
{
	int item,height;
	RBT *root;
}ROOT;
void main()
{
	ROOT *T=(ROOT *)Create_Tree();
	RBT *z;
	int key,opt;
	do
	{
		printf("\n\n\tEnter the Options\n\t1. for Insert\n\t2. for Delete\n\t3. for Inorder traversal\n\t4. for\n\t5. for Exit\n\t\t\t:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\n\tEnter the data to be insert :");
				scanf("%d",&key);
				Insert(T,key);
				break;
			case 2:
				printf("\n\tEnter the data to be delete :");
				scanf("%d",&key);
				Delete(T,key);
				break;
			case 3:
				Inorder(T->root);
				break;
			case 4:printf("\n\n\t\t : \t%d",Height(T->root));
				break;
			case 5:break;
			default:printf("");
		}
	}while(opt-5);
}
