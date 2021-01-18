//
// Created by 承苏凯 on 2021/1/18.
// rear = (front + count) % MaxSize
//

#ifndef DS_CCQUEUE2_H
#define DS_CCQUEUE2_H

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front;
    int count;
} QuType;

void InitQueue(QuType *&qu) {
    qu = (QuType *) malloc(sizeof(QuType));
    qu->front = 0;
    qu->count = 0;
}

bool EnQueue(QuType *&qu, ElemType e) {
    int rear;
    if (qu->count == MaxSize) {
        return false;
    } else {
        rear = (qu->front + qu->count) % MaxSize;
        rear = (rear + 1) % MaxSize;
        qu->data[rear] = e;
        qu->count++;
        return true;
    }
}

bool DeQueue(QuType *&qu, ElemType &e) {
    int rear;
    if (qu->count == 0) {
        return false;
    } else {
        qu->front = (qu->front + 1) % MaxSize;
        e = qu->data[qu->front];
        qu->count--;
        return true;
    }
}

bool QueueEmpty(QuType * qu){
    return qu->count == 0;
}

#endif //DS_CCQUEUE2_H
