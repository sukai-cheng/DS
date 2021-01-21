#include "iostream"
#include "SquentialStack.h"

using namespace std;

int main() {

    int n;
    cin >> n;
    SqlStack *stk;
    InitStack(stk);
    for (int i = 1; i < n; i++) {
        push(stk, i);
    }
    printStack(stk);
    return 0;
}


