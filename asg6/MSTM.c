#include<stdlib.h>
#include<stdio.h>
enum chrom{white,black};
struct vertex
{
	int rank,p,root,key;
	struct vertex *perent;
	enum chrom color;
	struct edge *edgep;
};
int main()
{  
	int name,num_vex=0,i=0,opt,s,e,w,E=0;
	printf("\n\t\tEnter the Total Number of Vertices :");
	scanf("%d",&num_vex);
	struct vertex G[num_vex];
	Initialize(G,num_vex);
	FILE *fp;
	fp=fopen("graph","r");
	for(fscanf(fp,"%d%d%d",&s,&e,&w);s;fscanf(fp,"%d%d%d",&s,&e,&w))
	{
		insert_edge(G,s-1,e-1,w);E++;
		insert_edge(G,e-1,s-1,w);E++;
	}
	fclose(fp);
	do
	{
		printf("\n\n\tEnter the option : \n\t1. for insert Edge\n\t2. for Delete Edge\n\t3. for List Representation\n\t");
		printf("4. for Prim\'s Algorithm for MST \n\t5. for Kruskal\'s Algorithm For MST\n\t6. for Exit\n\t\t\t: "); 
		scanf("%d",&opt);
		switch(opt)
		{
			case 5:
				MST_Kruskal(G,num_vex,E);
				break;
			case 3:
				show_edge(G,num_vex);
				break;
			case 1:	
				printf("\n\tEnter the start point of edge :\t");
				scanf("%d",&s);
				printf("\n\tEnter the end point of edge :\t");
				scanf("%d",&e);
				printf("\n\tEnter the weight of edge :\t");
				scanf("%d",&w);
				if(s<=num_vex && e<=num_vex && s>0 && e>0)
				 	if(!find_edge(G,s-1,e-1))
				 	{	
				 		insert_edge(G,s-1,e-1,w);E++;
				 		insert_edge(G,e-1,s-1,w);E++;
						printf("\tEdge Inserted Successfully\n\n");
					}
				 	else
						printf("\tEdge is already Exist\n\n");
				else
						printf("\tSuch Vertices not Exist\n\n");
				break;
			case 2:	
				printf("\n\tEnter the start point of edge :\t");
				scanf("%d",&s);
				printf("\n\tEnter the end point of edge :\t");
				scanf("%d",&e);
				if(find_edge(G,s-1,e-1))
				{
					edge_delete(G,s-1,e-1);E--;
					edge_delete(G,e-1,s-1);E--;
					printf("\tEdge Deleted Successfully\n\n"); 
				}
				else
					printf("\tEdge Not Exist\n\n"); 
				break;
			case 4:
				printf("\n\tEnter the start point of Graph :\t");
				scanf("%d",&s);
				Prim(G,s,num_vex);
				break;
			case 6:	break;
			default:printf(" wrong input \n");
		}
	}while(opt-6);	
}
