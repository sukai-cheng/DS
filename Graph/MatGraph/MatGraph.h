//
// 邻接表的表现形式
// Created by 承苏凯 on 2021/1/21.
//

#ifndef DS_MATGRAPH_HÏ

#define MaxVertexNum 100 /*最大顶点数*/
typedef int Vertex; /*顶点下标表示顶点，为整型*/
typedef int WeightType; /*边的权值设为整型*/
typedef char DataType;

/*边的定义*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

/**
 * 邻接点
 */
typedef struct AdjVnode *PtrToAdjNode;
struct AdjVnode{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjNode Next;
};

/**
 * 顶点表头结点(相当于邻接表)
 */
typedef struct Vnode{
    PtrToAdjNode FirstEdge; /*指向第一个邻接点*/
    DataType data;
}AdjList[MaxVertexNum];

/**
 * 图结点的定义
 * */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //number of vertex
    int Ne; //number of edge
    AdjList G; // 邻接表G
};
typedef PtrToGNode LGraph;

/**
 * 初始化带有VertexNum个顶点但没有边的图
 * @param VertexNum
 * @return
 */
LGraph CreateGraph(int VertexNum){
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V = 0; V < Graph->Nv; V++){
        Graph->G[V].FirstEdge = nullptr;
    }
}

/**
 * 插入边
 * @param Graph
 * @param E
 */
void InsertEdge(LGraph Graph, Edge E){

    PtrToAdjNode NewNode;

    NewNode = (PtrToAdjNode)malloc(sizeof(struct AdjVnode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    /*头插法*/
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
}

/**
 * 构建图
 * @return
 */
LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0 ; i < Graph->Ne; i++){
            scanf("%d %d %d", &E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph, E);
        }
    }
}

#endif //DS_MATGRAPH_H
