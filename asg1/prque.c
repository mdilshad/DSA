#include<stdio.h>
#include<stdlib.h>
#include"proto.h"
int main()
{
	int opt,i,pos,j,n,key;
	printf("\n\tEnter the number of element : ");
	scanf("%d",&n);
	int A[n];
	do
	{
		printf("\n\tenter the option : \n\t1. for creation\n\t2. for Extract Maximum\n\t3. for insert key\n\t4. for Maximum Value\n\t5. for increase key\n\t6. for show\n\t7. for exit\n\t\t\t: "); 
		scanf("%d",&opt);
		switch(opt)
		{
		case 1:
			for(i=1;i<=n;i++)
			{
				printf("\n\tEnter the data %d : ",i);
				scanf("%d",&A[i-1]);
			}
			build_heap(A,n);
			break;
		case 2:	
			printf("\nMaximum number is %d ",heap_extract_max(A,&n));
			break;
		case 3:
			printf("\n\tEnter the data : ");
			scanf("%d",&key);
			heap_insert(A,key,&n);
			break;
		case 4:
			printf("\nMaximum number is %d ",maximum(A));
			break;
		case 5:
			printf("\n\tEnter the Position : ");
			scanf("%d",&pos);
			printf("\n\tEnter the data : ");
			scanf("%d",&key);
			increase_key(A,pos,key);
			break;
		
		case 6:
			show(A,n);break;
		case 7:break;
		default:printf(" wrong input \n");
		}
	}while(opt-7);
}
