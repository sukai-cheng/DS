//
// Created by 承苏凯 on 2021/1/7.
//

#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H

#include "algorithm"
#include "cstdlib"

using namespace std;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node * next;
}LinkNode;

/**
 * 头插法
 * @param L
 * @param a
 * @param n
 */
void CreateListF(LinkNode* &L, ElemType a[], int n){
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode)); //dummyHead
    L->next = nullptr;
    for(int i = 0; i < n; i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

/**
 * 尾插法
 * @param L
 * @param a
 * @param n
 */
void CreateListR(LinkNode* &L,ElemType a[],int n){
    LinkNode *s,*r;
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = nullptr;
    r = L;
    for(int i = 0; i < n; i++){
        s = (LinkNode*)malloc(sizeof(LinkNode));
        r->next = s;
        r = s;
    }
    r->next = nullptr; //尾结点的next域置空
}
/**
 * 初始化链表
 * @param L
 */
void InitList(LinkNode* &L){
    L = (LinkNode*)malloc(sizeof (LinkNode));
    L->next = nullptr;
}

/**
 * 销毁链表
 * @param L
 */
void DestroyList(LinkNode* &L){
    LinkNode* pre = L;
    LinkNode* p = L->next;

    while(p!= nullptr){
        free(pre);
        pre = p;
        p = p->next;
    }

    free(pre);
}

/**
 * 判断链表是否为空
 * @param L
 * @return
 */
bool ListEmpty(LinkNode L){
    return (L.next == nullptr);
}

/**
 * 线性表长度
 * @param L
 * @return
 */
int ListLength(LinkNode* L){
    int len = 0;
    LinkNode* p = L;
    while(p->next != nullptr){
        len++;
        p = p->next;
    }
    return len;
}

/**
 * 输出链表
 * @param L
 */
void DispList(LinkNode* L){
    LinkNode *p = L;
    while(p->next != nullptr){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 求链表某个元素的值
 * @param L
 * @param i
 * @return
 */
bool GetElem(LinkNode* L,int i,ElemType e){
    int j = 0;
    LinkNode *p = L->next;
    if(i <= 0) return false;
    while(p != nullptr && j < i){
        j++;
        p = p->next;
    }

    if(p == nullptr){
        printf("can't find val");
        return false;
    }

    e = p->data;
    return true;
}

/**
 * 按元素值查找并返回逻辑序号
 * @param L
 * @param e
 * @return
 */
int LocateElem(LinkNode* L,ElemType e){
    LinkNode *p = L->next;
    int k = 1;
    if(p == nullptr){
        printf("链表为空");
        return 0;
    }

    while(p != nullptr && p->data != e){
        p = p->next;
        k++;
    }
    if(p == nullptr){
        printf("链表中没有值为e的结点");
        return 0;
    }else {
        return p->data;
    }
}

/**
 * 在逻辑位置为i的地方插入结点e
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(LinkNode* &L,int i,ElemType e){
    LinkNode *p = L;
    LinkNode *s;
    int j = 0;
    if(i <= 0) return false;

    while(j < i - 1 && p != nullptr){
        p = p->next;
        j++;
    }

    if(p == nullptr){
        return false;
    }else{
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

/**
 * 删除指定位置的结点
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(LinkNode* &L, int i, int e){
    int j = 0;
    LinkNode *p = L;
    LinkNode *q;
    if(i <= 0) return false;

    while(p != nullptr && j < i-1){
        p = p->next;
        j++;
    }

    if(p == nullptr) {
        return false;
    }else{
         q = p->next;
         if(q == nullptr){
             return false;
         }
         e = q->data;
         p->next = q->next;
         free(q);
         return true;
    }

}


#endif //DS_LINKEDLIST_H
