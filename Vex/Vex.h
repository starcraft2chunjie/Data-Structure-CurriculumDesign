#define MAX_VERTEX_NUM 20
#define TRUE 1
#define FALSE -1

#define SUCCESS 1
#define FAILURE -1

typedef struct ArcNode{
    int adjvex;   //该弧所指向的顶点的位置
    struct ArcNode * nextarc; //指向下一条弧的指针
    int info; //该弧相关信息的指针
}ArcNode;

typedef struct VNode{
    int data;
    int index;  
    ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;  //图的当前顶点数和弧数
    int kind;  //图的种类标志
}ALGraph;

typedef struct QNode{
    int index;
    struct QNode * next;
}QNode;
typedef struct {
    QNode * front;
    QNode * rear;
}LinkQueue;

int InitQueue(LinkQueue * Q);
int EnQueue(LinkQueue * Q, int index);
int Dequeue(LinkQueue * Q);
int initGraph(ALGraph * G);
int compare(VNode * u, VNode * v);
int CreateGraph(ALGraph * G, int length_Node, int * V, int rela_Node, int VR[][2]);
int DestroyGraph(ALGraph * G);
int LocateVex(ALGraph * G, int u);
int GetVex(ALGraph * G, int u);
int PutVex(ALGraph * G, int u, int value);
int FirstAdjVex(ALGraph * G, int u);
int NextAdjVex(ALGraph * G,  int u, int w);
int InsertVex(ALGraph * G, int u);
int DeleteVex(ALGraph * G, int u);
int InsertArc(ALGraph * G, int u, int w);
int DeleteArc(ALGraph * G, int u, int w);
int DFSTraverse(ALGraph * G, void(* visit)(int data));
int BFSTraverse(ALGraph * G, LinkQueue * Q, void(* visit)(int data));
void visit(int data);
void DFS(ALGraph * G, int v);
VNode * createVNode(ALGraph * G, int value,int rela_Node, int VR[]);


