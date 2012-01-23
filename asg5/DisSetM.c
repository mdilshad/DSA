#include<stdlib.h>
#include<stdio.h>
struct vertex
{
	int rank,p,root;
	struct edge *edgep;
	struct vertex *vertexp;
};
int main()
{  
	int name,num_vex=0,i=0,opt,s,e;
	char a,b;
	printf("\n\t\tEnter the Total Number of Vertices :");
	scanf("%d",&num_vex);
	struct vertex G[num_vex];
	Initialize(G,num_vex);
	FILE *fp;
	fp=fopen("graph","r");
	for(fscanf(fp,"%d%d",&s,&e);s;fscanf(fp,"%d%d",&s,&e))
		insert_edge(G,s-1,e-1);
	fclose(fp);
	do
	{
		printf("\n\n\tEnter the option : \n\t1. for Vertex Details \n\t2. for List Representation\n\t3. for insert Edge\n\t");
		printf("4. for Delete Edge\n\t5. for \n\t6. for Exit\n\t\t\t: "); 
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				vertex_detail(G,num_vex);
				break;
			case 2:
				show_edge(G,num_vex);
				break;
			case 3:	
				printf("\n\tEnter the start point of edge :\t");
				scanf("%d",&s);
				printf("\n\tEnter the end point of edge :\t");
				scanf("%d",&e);
				if(s<=num_vex && e<=num_vex && s>0 && e>0)
				 	if(insert_edge(G,s-1,e-1))
						printf("\tEdge Inserted Successfully\n\n");
					
				 	else
						printf("\tEdge is already Exist\n\n");
				else
						printf("\tSuch Vertices not Exist\n\n");
				break;
			case 4:	
				printf("\n\tEnter the start point of edge :\t");
				scanf("%d",&s);
				printf("\n\tEnter the end point of edge :\t");
				scanf("%d",&e);
				if(find_edge(G,s-1,e-1))
				{
					edge_delete(G,s-1,e-1);
					printf("\tEdge Deleted Successfully\n\n"); 
				}
				else
					printf("\tEdge Not Exist\n\n"); 
				break;
			case 5:
				Connected_Component(G,num_vex);
				break;
			case 6:	break;
			default:printf(" wrong input \n");
		}
	}while(opt-6);	
}
