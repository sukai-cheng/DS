
#include "SqlList.h"

using namespace std;

int main() {

    SqlList* L;
    int k = 0;
    int arr[] = {1,2,3,4,5};
    CreateList(L,arr,5);
    LocateElem(L,4);
    ListInsert(L,5,9);
    ListDelete(L,5,k);

    PrintList(L);
    return 0;
}


