#include <iostream>
#include "SqQueue.h"

using namespace std;

int main() {

    int n;
    cin >> n;
    SqQueue *queue;
    InitQueue(queue);
    for (int i = 1; i <= n; ++i) {
        enQueue(queue, i);
    }

    for (int i = 1; i <= n; ++i) {
        deQueue(queue, i);
    }

    cout << QueueEmpty(queue);

    return 0;
}


