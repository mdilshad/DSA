nclude<stdlib.h>
#include<stdio.h>
#include"graph.h"
struct graph
{
	int count;
	struct vertex *head;
};
void directed(struct graph *G,int opt1)
{
	char name,s,e;
	int opt2;				
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
			if(!find_edge(G,s,e))
			{
				if(insert_edge(G,s,e))
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
			edge_delete(G,s,e);
			if(!find_edge(G,s,e))
				printf("\tEdge Deleted Successfully\n\n");
			break;
		case 5:
			do
			{
				printf("\n\n\tEnter the option for DIRECTED GRAPH : \n\t1. for Matrix Representation\n\t2. for List Representation\n\t3. for DFS\n\t4. for Print the Path\n\t5. for Distance between two vertices \n\t6. for Vertex Details \n\t7. for Edit Graph\n\t8. for Exit\n\t\t\t: "); 
				scanf("%d",&opt2);
				option1(G,opt2);
			}while(opt2-7);
			break;
		case 6:	
			free_graph(G);
			break;
		default:printf(" wrong input \n");
	}
}
void option1(struct graph *G,int opt2)
{
	char name,s,e;				
	switch(opt2)
	{
		case 1:
			matrix_rep(G);
			break;
		case 2:	
			show_edge(G);
			break;
		case 3:	
			DFS(G);
			break;
		case 4:	
			printf("\n\tEnter the start point of edge :\t");
			getchar();
			scanf("%c",&s);
			printf("\n\tEnter the end point of edge :\t");
			getchar();
			scanf("%c",&e);
			print_path(G,s,e);
			break;
		case 5:	printf("\n\tEnter the start point of edge :\t");
			getchar();
			scanf("%c",&s);
			printf("\n\tEnter the end point of edge :\t");
			getchar();
			scanf("%c",&e);
			printf("\n%d",distance(G,s,e));
			break;
		case 6:
			printf("\n\tEnter the Vertex :\t");
			getchar();
			scanf("%c",&s);
			vertex_detail(G,s);
			break;	
		case 7:
			break;
		case 8:
			exit(0);
			break;
		default:printf("2wrong input \n");
		}
}
void undirected(struct graph *G,int opt1)
{
	char name,s,e;
	int opt2;				
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
			if(!find_edge(G,s,e))
			{
				insert_edge(G,s,e);
				if(insert_edge(G,e,s))
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
				edge_delete(G,e,s);
					printf("\tEdge Deleted Successfully\n\n");
			}
			else
				printf("\tEdge Not Exist\n\n");
			break;
		case 5:
			do
			{
				printf("\n\tEnter the option for UNDIRECTED GRAPH : \n\t1. for Matrix Representation\n\t2. for List Representation\n\t3. for BFS\n\t4. for Print the Path\n\t5. for Distance between two vertices \n\t6. for Vertex Details \n\t7. for Edit Graph\n\t8. for Exit\n\t\t\t: "); 
				scanf("%d",&opt2);
				option2(G,opt2);
			}while(opt2-7);
			break;
		case 6:	
			free_graph(G);
			break;
		default:printf(" wrong input \n");
		}
}
void option2(struct graph *G,int opt2)
{
	char name,s,e;				
	switch(opt2)
	{
		case 1:
			matrix_rep(G);
			break;
		case2:	
			show_edge(G);
			break;
		case 3:	
			printf("\n\tEnter the start point of edge :\t");
			getchar();
			scanf("%c",&s);
			BFS(G,s,1);
			break;
		case 4:	
			printf("\n\tEnter the start point of edge :\t");
			getchar();
			scanf("%c",&s);
			printf("\n\tEnter the end point of edge :\t");
			getchar();
			scanf("%c",&e);
			print_path(G,s,e);
			break;
		case 5:	printf("\n\tEnter the start point of edge :\t");
			getchar();
			scanf("%c",&s);
			printf("\n\tEnter the end point of edge :\t");
			getchar();
			scanf("%c",&e);
			printf("\n%d",distance(G,s,e));
			break;
		case 6:
			printf("\n\tEnter the Vertex :\t");
			getchar();
			scanf("%c",&s);
			vertex_detail(G,s);
			break;	
		case 7:
			break;
		case 8:
			//exit(0);
			break;
		default:printf("wrong input \n");
	}
}
int main()
{
	struct graph *G;
	int opt,opt1,opt2,opt3;
	char name,s,e;
	do
	{
		printf("\n\tCreate Graph : \n\t1. for Directed Graph\n\t2. for Undirected Graph\n\t3. for Exit\n\t\t\t: "); 
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				G=(struct graph *)create_graph(G);
				do
				{
					printf("\n\tEnter the option : \n\t1. for Insert Vertex\n\t2. for Delete Vertex\n\t3. for insert Edge\n\t");
					printf("4. for Delete Edge\n\t5. for Fix the Graph\n\t6. for Back\n\t\t\t: "); 
					scanf("%d",&opt1);
					directed(G,opt1);
				}while(opt1-6);break;
			case 2:
				G=(struct graph *)create_graph(G);
				do
				{
					printf("\n\tEnter the option : \n\t1. for Insert Vertex\n\t2. for Delete Vertex\n\t3. for insert Edge\n\t");
					printf("4. for Delete Edge\n\t5. for Fix the Graph\n\t6. for Back\n\t\t\t: "); 
					scanf("%d",&opt2);
					undirected(G,opt2);
				}while(opt2-6);break;
			case 3:
				break;
			default:printf(" wrong input \n");	
		}
	}while(opt-3);
}

