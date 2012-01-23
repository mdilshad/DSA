#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key,degree;
	struct node *p,*child,*sibling;
}Node;

typedef struct heap
{
	Node *head;
}Heap;
int main()
{
	Heap *H;
	Node *x;
	H=(Heap *)Make_Binomial_Heap();
	int key;
	int choice;
	while(1)
	{
		printf("\n\n\t\t1.Insert\n\t\t2.Delete\n\t\t3.Extract Min\n\t\t4.Search\n\t\t5.Decrease Key\n\t\t6.Minimum\n\t\t7.Print Root List\n\t\t8.Quit\n\t\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				//printf("\n\t\tEnter the key : ");
				//scanf("%d",&key);
				for(key=1;key <= 16;key++)
				{
					x = malloc(sizeof(Node));
					x->key = key;
					Binomial_Heap_Insert(&H,x);
				}
				break;
			case 2:
				printf("\n\t\tEnter the key : ");
				scanf("%d",&key);
				x=(Node *)Binomial_Heap_Search(H,key);
				if(x)
				{
					Binomial_Heap_Delete(&H,x);
					printf("\n\t\tKey Deleted Successfully");
				}
				else
					printf("\n\t\tKey Not Found");
				break;
			case 3:
				x = (Node *)Binomial_Heap_Extract_Min(&H);
				if(x)
					printf("\n\t\tMinimum Value is = %d\n",x->key);
				else
					printf("\n\t\tHeap is Empty");
				break;
			case 4:
				printf("\n\t\tEnter the key : ");
				scanf("%d",&key);
				if(Binomial_Heap_Search(H,key))
					printf("\n\t\tKey Founded");
				else
					printf("\n\t\tKey Not Found");
				break;
			case 5:
				printf("\n\t\tEnter the key : ");
				scanf("%d",&key);
				x=(Node *)Binomial_Heap_Search(H,key);
				if(x)
				{
					printf("\n\t\tEnter the key : ");
					scanf("%d",&key);
					Binomial_Heap_Decrease_Key(H,x,key);
					printf("\n\t\tKey Decreased Successfully");
				}
				else
					printf("\n\t\tKey Not Found");
				break;
			case 6:
				x = (Node *)Binomial_Heap_Minimum(H);
				if(x)
					printf("\n\t\tMinimum Value is = %d\n",x->key);
				else
					printf("\n\t\tHeap is Empty");
				break;
			case 7:
				printf("\n\t\tRoot list are -> ");
				print(H);
				break;
			case 8:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
