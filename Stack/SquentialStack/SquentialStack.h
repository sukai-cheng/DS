//
// Created by 承苏凯 on 2021/1/17.
//

#ifndef DS_SQUENTIALSTACK_H
#define DS_SQUENTIALSTACK_H

#include "iostream"

const int MaxSize = 50;

using namespace std;

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqlStack;

/**
 * 初始化
 * @param s
 */
void InitStack(SqlStack *&s) {
    s = (SqlStack *) malloc(sizeof(SqlStack));
    s->top = -1;
}

/**
 * 销毁栈
 * @param s
 */
void DestoryStack(SqlStack *&s) {
    free(s);
}

/**
 * 栈是否为空
 * @param s
 * @return
 */
bool StackEmpty(SqlStack *s) {
    return (s->top == -1);
}

/**
 * 向栈中添加一个元素e
 * @param s
 * @param e
 * @return
 */
bool push(SqlStack *&s, ElemType e) {
    //栈满的条件
    if (s->top == MaxSize - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

/**
 * 删除栈顶元素并返回该删除元素
 * @param s
 * @return
 */
bool Pop(SqlStack *&s, ElemType e) {
    //栈空
    if (s->top == -1) {
        return false;
    }

    e = s->data[s->top];
    s->top--;
    return true;
}

/**
 * 返回栈顶元素
 * @param s
 * @param e
 * @return
 */
bool GetTop(SqlStack *s, ElemType e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return e;
}

/**
 * 输出栈
 * @param s
 */
void printStack(SqlStack *s) {
    while (s->top != -1) {
        printf("%d ", s->data[s->top--]);
    }
}


#endif //DS_SQUENTIALSTACK_H
