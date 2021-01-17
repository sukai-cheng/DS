#include "iostream"
#include "DoubleLinkedList.h"

using namespace std;

int main() {

    int a[6] = {1,3,5,2,4,6};
    DLinkNode *L;
    CreateListF(L,a,6);
    ListPrint(L);

    return 0;
}


