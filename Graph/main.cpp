#include <iostream>

using namespace std;
const int MaxVertexNum = 10;
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; /*顶点数*/
    int Ne; /*边数*/
    WeightType G[MaxVertexNum][MaxVertexNum];
    WeightType Data[MaxVertexNum];
};
typedef PtrToGNode MGrapth;

typedef struct ENode *PtrToENode;
struct ENode{
    int V1,V2; /*有向边<v1 v2>*/
    WeightType Weight; /*权值*/
};
typedef PtrToENode Edge;

/**
 * 创建图
 * @param VertexNum
 * @return
 */
MGrapth CreateGraph(int VertexNum){

    MGrapth Grapgh;
    WeightType V,W;

//  创建结点
    Grapgh = (MGrapth)malloc(sizeof(struct GNode));
    Grapgh->Nv = VertexNum;
    Grapgh->Ne = 0;

//    初始化边
    for(V = 0; V < Grapgh->Nv; V++){
        for(W = 0; W < Grapgh->Nv; W++){
            Grapgh->G[V][W] = 0;
        }
    }

    return Grapgh;

}

/**
 * 插入边
 * @param Graph
 * @param E
 */
void InsertEdge(MGrapth Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
//    如果是无向图还要插入边<v2, v1>
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGrapth BuildGraph(){
    MGrapth Grapgh;
    Edge E;

}


int main() {
    int Nv,Ne;
    
    scanf("%d",&Nv);
    MGrapth graph = CreateGraph(Nv);
    scanf("%d",&(graph->Ne));
    if(graph->Ne != 0){

    }
    return 0;
}


