//
// 邻接矩阵的表现形式
// Created by 承苏凯 on 2021/1/21.
//

#ifndef DS_ADJGRAPH_H
#define DS_ADJGRAPH_H
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

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


#endif //DS_ADJGRAPH_H
