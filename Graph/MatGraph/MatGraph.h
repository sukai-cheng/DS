//
// 邻接矩阵的表现形式
// Created by 承苏凯 on 2021/1/21.
//

#ifndef DS_MATGRAPH_H
#define DS_MATGRAPH_H

#define MAXV 1000
typedef int InfoType;
typedef struct
{
    int no; //顶点编号
    InfoType info; //顶点携带的信息
}VertexType;

typedef struct
{
    int edges[MAXV][MAXV]; //邻接矩阵
    int n,e; //顶点数和边数
    VertexType vexs[MAXV]; //顶点信息
}MatGraph;

#endif //DS_MATGRAPH_H
