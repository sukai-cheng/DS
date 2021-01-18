#include "iostream"
#include "LinkedStack.h"

using namespace std;

int main() {

    LinkStNode *L;
    InitStack(L);
    int n;
    int e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Push(L, i);
    }
    Pop(L);
    GetTop(L,e);
    cout << e << endl;
    PrintStack(L);
    return 0;
}


