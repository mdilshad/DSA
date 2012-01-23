enum chrom{white,black};
struct vertex
{
	int rank,p,root;
	enum chrom color;
	struct edge *edgep;
};
struct edge
{
	int destin;
	struct edge *next;
};
void Initialize(struct vertex *G,int size);
int insert_edge(struct vertex *G,int s,int d);
int find_edge(struct vertex *G,int s,int d);
void edge_delete(struct vertex *G,int s,int d);
void show_edge(struct vertex *G,int size);
void Make_Set(struct vertex *G,int i);
int Find_Set(struct vertex *G,int i);
void Union(struct vertex *G,int x, int y);
void Connected_Component(struct vertex *G,int size);
void vertex_detail(struct vertex *G,int size);
