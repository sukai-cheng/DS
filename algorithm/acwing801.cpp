#include <iostream>

using namespace std;

/**
 * 返回最后一个1
 * @param n
 * @return
 */
int lowbit(int n){
    return n&-n;
}
int main() {

    int n;
    int res = 0;
    cin >> n;

    while(n){
        n -= lowbit(n);
        res++;
    }
    cout << res << endl;
    return 0;
}


