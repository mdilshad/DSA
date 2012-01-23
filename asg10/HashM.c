#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10
typedef struct node
{
	char data[50];
	struct node *next;
}Node;
Node *T[M];
int main()
{
	char str[50];
	int choice,i;
	for(i=0;i<M;i++)
	    T[i] = NULL;
	Node *x;
	FILE *fp;
	fp=fopen("Hash.txt","r");
	for(fscanf(fp,"%s",str);strcmp(str,"$$$");fscanf(fp,"%s",str))
		Insert(T,str);
	fclose(fp);
	while(1)
	{
		printf("\n\n\t\t1.Insert\n\t\t2.Delete\n\t\t3.Search\n\t\t4.Display\n\t\t5.Quit\n\t\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n\t\tEnter the string : ");
				scanf("%s",str);
				Insert(T,str);
				break;
			case 2:
				printf("\n\t\tEnter the string : ");
				scanf("%s",str);
				if(Delete(T,str))
					printf("\n\t\t Data Deleted ");
				else
					printf("\n\t\t Data Not found ");
				break;
			case 3:
				printf("\n\t\tEnter the string : ");
				scanf("%s",str);
				if(Search(T,str))
					printf("\n\t\t %s found ",str);
				else
					printf("\n\t\t Data Not found ");
				break;
			case 4:
				for(i = 0;i < M;i++)
				{
					x = T[i];
					printf("\n\t%2d",i+1);
					while(x)
					{
						printf("%20s",x->data);
						x = x->next;
					}
				}
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
