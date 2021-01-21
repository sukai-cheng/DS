//
// 邻接表的表现形式
// Created by 承苏凯 on 2021/1/21.
//

#ifndef DS_ADJGRAPH_H
#define DS_ADJGRAPH_H
#define MAXV 1000
typedef int InfoType;
typedef struct ANode
{
    int adjVex; //该边的终点编号
    struct ANode *nextarc; //指向下一个边结点
    InfoType info; //该边的权值信息
}ArcNode;

typedef struct Vnode
{
    InfoType data;
    ArcNode *firstarc; //指向边结点
}VNode;

typedef struct
{
    VNode adjlist[MAXV];//邻接表
    int n,e; //图中顶点和边数
}ALGraph;

#endif //DS_ADJGRAPH_H
