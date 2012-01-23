#include<stdlib.h>
#include<stdio.h>
#include"WDG.h"
struct graph
{
	int count;
	struct vertex *head;
};
void directed(struct graph *G,int opt1)
{
	char name,s,e;
	int opt2;				
	
}
void option1(struct graph *G,int opt2)
{
	char name,s,e;				
	switch(opt2)
	{
		case 1:
			//matrix_rep(G);
			break;
		case 2:	
			show_edge(G);
			break;
		case 3:	
			/*printf("\n\tTopological Sort Order is :\n\t");
			DFS(G);*/
			break;
		case 4:
			printf("\n\tEnter the Vertex :\t");
			getchar();
			scanf("%c",&s);
			Bellman_Ford(G,0,s);
			vertex(G);
			//print_path(G);
			break;
		case 5:	
			printf("\n\tEnter the Vertex :\t");
			getchar();
			scanf("%c",&s);
			Dijkstra(G,s);
			vertex(G);
			break;
		case 6:
			printf("\n\tEnter the Vertex :\t");
			getchar();
			scanf("%c",&s);
			//vertex_detail(G,s);
			break;	
		case 7:
			break;
		case 8:
			exit(0);
			break;
		default:printf("2wrong input \n");
		}
}
int main()
{
	struct graph *G;
	int opt1,opt2,w;
	char name,s,e;
	G=(struct graph *)create_graph(G);
	FILE *fp;
	fp=fopen("graph","r");
	for(fscanf(fp,"%c",&s);s!='$';fscanf(fp,"%c",&s))
		insert_vertex(G,s);
	for(fscanf(fp,"%c%c%d",&s,&e,&w);s!='$';fscanf(fp,"%c%c%d",&s,&e,&w))
		insert_edge(G,s,e,w);
	fclose(fp);
	do
	{
		printf("\n\n\tEnter the option : \n\t1. for Insert Vertex\n\t2. for Delete Vertex\n\t3. for insert Edge\n\t");
		printf("4. for Delete Edge\n\t5. for Fix the Graph\n\t6. for Exit\n\t\t\t: "); 
		scanf("%d",&opt1);
		switch(opt1)
		{
			case 1:
				printf("\n\tEnter the name : ");
				getchar();
				scanf("%c",&name);
				if(!find_vertex(G,name))
				{
					insert_vertex(G,name);
					printf("\tVertex Inserted Successfully\n\n");
				}
				else
					printf("\tVertex is already Exist\n\n");
				break;
			case 2:	
				printf("Enter the vertex for Delete :\t");
				getchar();
				scanf("%c",&name);
				if(find_vertex(G,name))
				{
					vertex_delete(G,name);
					printf("\tVertex Deleted Successfully\n\n");
				}
				else
					printf("\tVertex not Exist\n\n");
				break;
			case 3:	
				printf("\n\tEnter the start point of edge :\t");
				getchar();
				scanf("%c",&s);
				printf("\n\tEnter the end point of edge :\t");
				getchar();
				scanf("%c",&e);
				printf("\n\tEnter the Weight of Edge :\t");
				scanf("%d",&w);
				if(!find_edge(G,s,e))
				{
					if(insert_edge(G,s,e,w))
						printf("\tEdge Inserted Successfully\n\n");
					else
						printf("\tSuch Vertices not Exist\n\n");
				}
				else
					printf("\tEdge is already Exist\n\n");
				break;
			case 4:	
				printf("\n\tEnter the start point of edge :\t");
				getchar();
				scanf("%c",&s);
				printf("\n\tEnter the end point of edge :\t");
				getchar();
				scanf("%c",&e);
				if(find_edge(G,s,e))
				{
					edge_delete(G,s,e);
					printf("\tEdge Deleted Successfully\n\n"); 
				}
				else
					printf("\tEdge Not Exist\n\n"); 
				break;
			case 5:
				if(G->count>0)
				{
					do
					{
						printf("\n\n\n\tEnter the option for DIRECTED GRAPH : \n\t1. for Matrix Representation\n\t2. for List Representation\n\t3. for Topological Sort Order\n\t4. for Bellman Ford Algorithm for shortest path\n\t5. for Dijkestra Algorithm for shortest path \n\t6. for Vertex Details \n\t7. for Edit Graph\n\t8. for Exit\n\t\t\t: "); 
						scanf("%d",&opt2);
						option1(G,opt2);
					}while(opt2-7);
				}
				else
					printf("\n\tNo vertex exist\n\n");
				break;
			case 6:	
				free_graph(G);
				break;
			default:printf(" wrong input \n");
		}
	}while(opt1-6);	
}
