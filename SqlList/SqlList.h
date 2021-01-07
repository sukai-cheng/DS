#include <__bit_reference>
//
// Created by 承苏凯 on 2021/1/6.
//

#ifndef DS_SQLLIST_H
#define DS_SQLLIST_H
#include "cstdlib"
#include "algorithm"
#include "cstring"

using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct {
   ElemType data[MaxSize]; //存放线性表的元素
   int length; //存放线性表的长度
}SqlList; //顺序表类型

/**
 * 初始化线性表
 * @param L
 */
__unused void InitList(SqlList* &L){
    L = (SqlList*)malloc(sizeof(SqlList)); //分配线性表的空间
    L->length = 0;//置空线性表的长度为0
}
/*
 *
 * 将数组a的元素依此放入到顺序表中，并将n赋给顺序表的长度域*/
void CreateList(SqlList* &L,const ElemType a[],int n){
    L = (SqlList*)malloc(sizeof (SqlList));
    int k = 0;
    for (int i = 0; i < n; ++i) {
       L->data[i] = a[i];
       k++;
    }
    L->length = k;
}

/**
 * 将线性表的值打印出来
 */
void PrintList(SqlList* L){
    if(L->length == 0){
        printf("NULL");
        return;
    }
    for(int i = 0; i < L->length; i++){
        printf("%d ",L->data[i]);
    }
}

/**
 * 销毁线性表L
 * @param L
 */
__unused void DestroyList(SqlList* &L){
    free(L);
}

/**
 * 判断线性表是否为空
 * @param L
 * @return
 */
__unused bool ListEmpty(SqlList* L){
    return L->length == 0;
}

/**
 * 求线性表的长度
 * @param L
 * @return
 */
__unused int ListLength(SqlList* L){
    return L->length;
}

/**
 * 求线性表某个元素的值
 * @param L
 * @param i 逻辑序号
 * @param e
 * @return
 */
__used bool GetElem(SqlList* L,int i,ElemType e){
    if(i < 1 || i > L->length){
        return false;
    }
//    e = L->data[i-1];
    return true;
}

/**
 * 返回线性表中元素值为e的逻辑序号
 * @param L
 * @param e
 * @return
 */
__unused int LocateElem(SqlList* L,int e){
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i] == e){
            printf("%d\n",i+1);
            return i+1;
        }
    }
    return 0;
}

/**
 * 在逻辑序号为i的位置插入元素e
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqlList* &L,int i,ElemType e){
    if(i < 1 || i > L->length){
        printf("Insert number is error\n");
        return false;
    }
    for(int j = L->length - 1; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->data[i-1] = e;
    L->length++;
    return true;
}

/**
 * 删除线性表的第i个元素，并将删除的元素赋给变量e
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(SqlList* &L,int i,ElemType &e){
    if(i < 1 || i > L->length) return false;
    for(int j = i; i < L->length; i++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return true;
}

/**
 * 删除值为x的所有结点
 * @param L
 * @param x
 */
__unused void delnodel(SqlList* &L,ElemType x){
    int k = 0;
    for(int i = 0; i < L->length; i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

/**
 * 分界
 * @param L
 * @return
 */
__used void partitionl(SqlList* &L){

    ElemType pivot = L->data[0]; //以data[0]为基准
    int i = 0;
    int j = L->length-1;

    while(i < j){
       while(i < j && L->data[j]>pivot){
           j--;
       }
       while(i < j && L->data[i]<=pivot){
           i++;
       }
       if(i < j){
           swap(L->data[i],L->data[j]);
       }
    }
    swap(L->data[0],L->data[i]);
}





#endif //DS_SQLLIST_H
