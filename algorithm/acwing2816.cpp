#include <iostream>

using namespace std;

const int N = 1e6+10;
int a[N];
int b[N];

int main(){
    int n, m;cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for(int i = 0,j = 0; i < n; i++){
        while(j < m && b[j] < a[i]){
            j++;
        }
        if(b[j] != a[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
