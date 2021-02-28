#include <iostream>

using namespace std;

const int N = 1e6+10;
int a[N];
int b[N]; //存储a中的值出现的次数

int main() {

    int n;
    int len = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0,j = 0; i < n; i++){
        b[a[i]++];
        while (b[a[i]] > 1){
            b[a[j++]]--;
        }
        len = max(len,i-j+1);
    }
    cout << len;
    return 0;
}


