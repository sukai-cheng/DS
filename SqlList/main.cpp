
#include "SqlList.h"

using namespace std;

int main() {

    SqlList* L;
    int k = 0;
    int arr[] = {3,2,3,2,5};
    CreateList(L,arr,5);
    partitionl(L);
//    delnodel(L,2);

//    LocateElem(L,4);
//    ListInsert(L,5,9);
//    ListDelete(L,5,k);

    PrintList(L);
    return 0;
}


