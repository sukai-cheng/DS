#include <iostream>
/**
 * 5
 * 3 4 2 7 5
 */
using namespace std;
const int N = 100010;
int stk[N];
int tt;

int main() {

    int n; cin >> n;
    while (n--){
        int x;
        scanf("%d",&x);
        while(tt && stk[tt] >= x) tt--; //如果栈不空且x需要找到第一个小于本身的数，那就出栈直至满足小于x
        if(!tt) cout << -1 << ' ';//如果栈为空则输出-1
        else{
            cout << stk[tt] << ' ';//输出满足条件的数
        }
        stk[++tt] = x;
    }
    return 0;
}


