#include <iostream>
#include <deque>
/**
 * 单调队列问题
 * 1 3 -1 -3 5 3 6 7
 */
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N];

int main() {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int hh = 0, tt = -1; //队头和队尾
    for (int i = 0; i < n; i++) {
        if (hh <= tt && q[hh] < i - k + 1) hh++; //如果队首元素超过区间范围
        while (hh <= tt && a[i] <= a[q[tt]]) tt--;   //新加入的元素如果小于等于当前元素则队尾删除队列中比它大的元素,为什么是<=？保证严格单调
        q[++tt] = i;//将新的元素加入到队列中
        if (i >= k - 1) printf("%d ", a[q[hh]]); //如果满足区间中有个元素的话就输出队头，因为线性数组队头是最大的
    }
    puts("");//换行
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && q[hh] < i - k + 1) hh++;
        while (hh <= tt && a[i] >= a[q[tt]]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    return 0;
}


