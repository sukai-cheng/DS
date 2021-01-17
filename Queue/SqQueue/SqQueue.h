//
// Created by 承苏凯 on 2021/1/18.
//

#ifndef DS_SQQUEUE_H
#define DS_SQQUEUE_H

#include "iostream"
#include "cstdlib"

const int MaxSize = 50;
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

/**
 * 初始化
 * @param q
 */
void InitQueue(SqQueue *&q) {
    q = (SqQueue *) malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

/**
 * 销毁队列
 * @param q
 */
void DestroyQueue(SqQueue *&q) {
    free(q);
}

/**
 * 判断队列是否为空
 * @param q
 * @return
 */
bool QueueEmpty(SqQueue *q) {
    return (q->front == q->rear);
}

/**
 * 入队列
 * @param q
 * @param e
 * @return
 */
bool enQueue(SqQueue *&q, ElemType &e) {
    if (q->rear == MaxSize - 1) {
        return false;
    }
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

/**
 * 出队列
 * @param q
 * @return
 */
bool deQueue(SqQueue *&q, ElemType &e) {
    if (q->front == q->rear) {
        return false;
    }
    q->data[q->front] = e;
    q->front++;
    return true;
}


#endif //DS_SQQUEUE_H
