//
// Created by 承苏凯 on 2021/1/21.
//

#ifndef DS_CARTESIAN_H
#define DS_CARTESIAN_H

#define MaxCol 10
typedef int ElemType;

/**
 * 列结点
 */
typedef struct Node1 {
    ElemType data[MaxCol]; //每一列的结点
    struct Node1 *next; //指向下一个列结点
} DList;

/**
 * 头结点
 */
typedef struct Node2 {
    int Row, Col; //记录多少行和列
    DList *next; //指向第一个列结点
} HList;

/**
 * 创建表
 * @param h
 */
void CreateTable(HList *&h) {
    int i, j;
    DList *r, *s; // r表示尾结点(尾插法需要一个尾结点指向最后一个结点)
    h = (HList *) malloc(sizeof(HList));//创建头结点
    printf("行数，列数：");
    scanf("%d %d", &h->Row, &h->Col);//指明行和列
    for (int i = 0; i < h->Row; i++) {
        printf("第%d行: ", i + 1);
        s = (DList *) malloc(sizeof(HList));
        for (int j = 0; j < h->Col; j++) { //插入结点
            scanf("%d", &s->data[i]);
        }
        if (h->next == nullptr) { //如果当前是第一个结点的话就让头结点的next指针指向该列结点
            h->next = s;
        } else {
            r->next = s;
        }
        r = s;
    }
    r->next = nullptr;
}

/*销毁表*/
void DestroyTable(HList *&h) {
    DList *pre = h->next;
    DList *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
    free(h);
}

/*展示表*/
void DispTable(HList *h) {

    DList *p = h->next;
    while (p != nullptr) {
        for (int j = 0; j < h->Col; j++) {
            printf("%4d", p->data[j]);
        }
        printf("\n");
        p = p->next;
    }
}

/*
 * 笛卡尔积连接表
 */
void LinkTable(HList *h1, HList *h2, HList *&h) {
    int i, j, k; //连接字段
    DList *p = h1->next, *q, *s, *r;
    printf("连接字段是：第1个表序号，第2个表序号：");
    scanf("%d %d", &i, &j);
    h = (HList *) malloc(sizeof(HList));
    h->Row = 0;
    h->Col = h1->Col + h2->Col;
    h->next = nullptr;
    while (p != nullptr) {
        q = h2->next;
        while (q != nullptr) {
            if (p->data[i - 1] == q->data[j - 1]) { // 如果满足连接条件
                s = (DList *) malloc(sizeof(DList));
                for (k = 0; k < h1->Col; k++) {
                    s->data[k] = p->data[k];
                }
                for (k = 0; k < h2->Col; k++) {
                    s->data[k + h1->Col] = q->data[k];
                }
                if (h->next == nullptr) {
                    h->next = s;
                } else {
                    r->next = s;
                }
                r = s;
                h->Row++;
            }
            q = q->next;
        }
        p = p->next;
    }
    r->next = nullptr;
}


#endif //DS_CARTESIAN_H


