//
// 邻接矩阵的表现形式
// Created by 承苏凯 on 2021/1/21.
//

#include "queue"

using namespace std;

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
Vertex Visited[MaxVertexNum];

/**
 * 边的定义
 */
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv; //顶点个数
    int Ne; //边个数
    WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵
    DataType Data[MaxVertexNum]; //存顶点的数据
};
typedef PtrToGNode MGraph;

/**
 * 创建一个有VertexNum个顶点但没有边的图
 * @param VertexNum
 * @return
 */
MGraph CreateGraph(int VertexNum) {
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph) malloc(sizeof(GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++) {
        for (W = 0; W < Graph->Nv; W++) {
            Graph->G[V][W] = INFINITY;
        }
    }
    return Graph;
}

/**
 * 插入一条边
 * @param Graph
 * @param E
 */
void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->weight;
    Graph->G[E->V2][E->V1] = E->weight;
}

/**
 * 构建图
 * @return
 */
MGraph BuildGraph() {
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);
    CreateGraph(Nv);

    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        E = (Edge) malloc(sizeof(struct ENode));

        for (i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->weight);
            InsertEdge(Graph, E);
        }
    }

    for (V = 0; V < Graph->Nv; V++) {
        scanf("%c", &(Graph->Data[V]));
    }
    return Graph;
}

/**
 * 访问结点
 * @param V
 */
void Visit(Vertex V) {
    printf("正在访问的顶点是%d\n", V);
}

/**
 * 判断顶点V和W之间是否有一条边
 * @param Graph
 * @param V
 * @param W
 * @return
 */
bool isEdge(MGraph Graph, Vertex V, Vertex W) {
    return Graph->G[V][W] < INFINITY ? true : false;
}

/**
 * 广度优先遍历
 * @param Graph
 * @param S
 * @param Visit
 */
void BFS(MGraph Graph, Vertex S, void (*Visit)(Vertex)) {
    queue<Vertex> Q;
    Vertex V, W;
    Visit(S);
    Visited[S] = true;
    Q.push(S);
    while (!Q.empty()) {
        V = Q.front();
        Q.pop();
        for (W = 0; W < Graph->Nv; W++) {
            if (!Visited[W] && isEdge(Graph, V, W)) {
                Visit(W);
                Visited[W] = true;
                Q.push(W);
            }
        }
    }
}

