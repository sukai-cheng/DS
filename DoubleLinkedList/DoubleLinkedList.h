//
// Created by 承苏凯 on 2021/1/7.
//

#ifndef DS_DOUBLELINKEDLIST_H
#define DS_DOUBLELINKEDLIST_H

#include "algorithm"
#include "cstdlib"

using namespace std;
typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior;
    struct DNode *next;

} DLinkNode;

/**
 * 头插法建立链表
 * @param L
 * @param a
 * @param n
 */
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->prior = L->next = nullptr;
    for (int i = 0; i < n; i++) {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != nullptr) //要判断一下L是否存在数据结点
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}

/**
 * 尾插法
 * @param L
 * @param a
 * @param n
 */
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    DLinkNode *r;
    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->prior = L->next = nullptr;
    r = L;
    for (int i = 0; i < n; i++) {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;//相当于r = r.next
    }
    r->next = nullptr; //尾结点的next域置为NULL

}

/**
 * 在链表中的第i个位置上插入值为e的结点
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(DLinkNode *&L, int i, ElemType e) {

    int j = 0;
    DLinkNode *p = L;
    DLinkNode *s;
    if (i <= 0) return false;

    //找到第i-1的位置
    while (j < i - 1 && p != nullptr) {

        j++;
        p = p->next;
    }

    if (p == nullptr) {
        return false;
    } else {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        if (p->next != nullptr) //如果p结点存在后继结点的话，修改前驱指针
            p->next->prior = s; //如果没有上面的约束条件这里的p->next->prior可能会产生NPE
        p->next = s;
        s->prior = p;
        return true;
    }

}

/**
 * 删除结点
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(DLinkNode *&L, int i, ElemType &e) {
    int j = 0;
    DLinkNode *p = L, *q;
    if (i <= 0) return false;

    while (j < i - 1 && p != nullptr) {
        j++;
        p = p->next;
    }

    if(p == nullptr){
        return false;
    }else{
        q = p->next; //q指向第i个结点
        if(q == nullptr){
            return false;
        }
        e = q->data;
        p->next = q->next;
        if(q->next != nullptr){
            q->next->prior = p;
        }
        free(q);
        return true;
    }

}




#endif //DS_DOUBLELINKEDLIST_H
