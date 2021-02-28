#include <stdio.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

void Print(List L) {
    while (L) {
        printf("%d ", L->Data);
    }
}

List Insert(List L, ElementType X);

int main() {
    List L;
    ElementType X;

    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert(List L, ElementType X) {
    List cur = L, pre = L;
    while (cur && cur->Data < X) {
        pre = cur;
        cur = cur->Next;
    }
    List el;
    el->Data = X;
    el->Next = pre->Next;
    pre->Next = el;

    return L;
}