//
// Created by 承苏凯 on 2021/1/22.
//

#ifndef DS_HOWTOBUILDGRAPH_H

#define MaxVertexNum 100
typedef int WeightType;
typedef int DataType;
typedef int Vertex;

/**
 * 创建图结点
 */
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Date[MaxVertexNum];
};
typedef PtrToGNode MGraph; //邻接矩阵存储的图类型

/**
 * 创建边结点
 */
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex v1;
    Vertex v2;
    WeightType Weight;
};
typedef PtrToENode Edge;

/**
 * 初始化没有边的图
 * @param VertexNum
 * @return
 */
MGraph CreateGraph(int VertexNum) {
    MGraph Graph;
    Vertex v, w; //两个顶点

    Graph = (MGraph) malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (v = 0; v < Graph->Nv; v++) {
        for (w = 0; w < Graph->Nv; w++) {
            Graph->G[v][w] = 0;
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
    Graph->G[E->v1][E->v2] = E->Weight;
}

/**
 * 建立图
 * @param Graph
 * @param Nv
 * @return
 */
MGraph BuildGraph(MGraph Graph, int Nv) {
    Vertex a, b;
    Edge E;
    Graph = CreateGraph(Nv);
    scanf("%d", Graph->Ne);
    while (Graph->Ne != 0) {
        E = (Edge) malloc(sizeof(struct ENode));
        for (int i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->v1, &E->v2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

#endif
