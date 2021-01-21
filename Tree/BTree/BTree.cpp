#include <iostream>
#include "BTree.h"
using namespace std;

int main() {

    BTNode *b;
    CreateBTree(b,"A(B(D,G),C(E,F))");
    DisBTree(b);
    return 0;
}


