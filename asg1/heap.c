#include<stdio.h>
#include<stdlib.h>
#include"proto.h"
int main()
{
	int opt,i,p,j,n;
	printf("\n\tEnter the number of element : ");
	scanf("%d",&n);
	int A[n];
	do
	{
		printf("\n\tenter the option : \n\t1. for creation\n\t2. for heap Sort\n\t3. for show\n\t4. for exit\n\t\t\t: "); 
		scanf("%d",&opt);
		switch(opt)
		{
		case 1:
			for(i=1;i<=n;i++)
			{
				printf("\n\tEnter the data %d : ",i);
				scanf("%d",&A[i-1]);
			}
			break;
		case 2:	
			heap_sort(A,n);
			break;
		case 3:	
			show(A,n);break;
		case 4:break;
		default:printf(" wrong input \n");
		}
	}while(opt-4);
}
