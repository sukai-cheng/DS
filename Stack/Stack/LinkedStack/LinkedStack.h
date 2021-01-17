//
// Created by 承苏凯 on 2021/1/17.
//

#ifndef DS_LINKEDSTACK_H
#define DS_LINKEDSTACK_H

#include "iostream"

using namespace std;

typedef int ElemType;

typedef struct linknode {
    ElemType data;
    struct linknode *next;
} LinkStNode;

/**
 * 初始化
 * @param s
 */
void InitStack(LinkStNode *&s) {
    s = (LinkStNode *) malloc(sizeof(LinkStNode));
    s->next = nullptr;
}

/**
 * 销毁栈
 * 时间复杂度O(n)
 * @param s
 */
void DestroyStack(LinkStNode *&s) {
    LinkStNode *pre = s;
    LinkStNode *p = s->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }

    //把最后一个结点删除
    free(pre);
}

/**
 * 判断链栈是否为空
 */
bool StackEmpty(LinkStNode *s) {
    return (s->next == nullptr);
}

/**
 * 插入结点e
 * @param s
 * @param e
 */
void Push(LinkStNode *&s, ElemType e) {
    LinkStNode *p;
    p = (LinkStNode *) malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

/**
 * 弹出元素
 * @param s
 * @return
 */
bool Pop(LinkStNode *&s) {
    LinkStNode *p;
    if (StackEmpty(s)) {
        return false;
    }

    p = s->next;
    s->next = p->next;
    free(p);
    return true;

}

/**
 * 获得栈顶元素
 * @param s
 * @param e
 * @return
 */
bool GetTop(LinkStNode *s, ElemType &e) {
    if (s->next == nullptr) {
        return false;
    }
    e = s->next->data;
    return true;
}

/**
 * 输出栈
 * @param s
 */
void PrintStack(LinkStNode *s) {
    LinkStNode *p = s->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
}


#endif //DS_LINKEDSTACK_H
