#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
int state[N];
int n;
vector<int> vect;
vector<int> res;
vector<vector<int>> ans;

int dfs() {
    if (res.size() == n) {
        ans.push_back(res);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (state[i] == 1) continue;

        res.push_back(vect[i]);
        state[i] = 1;

        dfs();

        state[i] = 0;
        res.pop_back();
    }
    return 0;
}

int main() {

    for (n = 1; n <= 8; ++n) {
        vect.clear();
        ans.clear();
        for (int i = 1; i <= n; i++) {
            vect.push_back(i);
        }

        dfs();

        for (auto item : ans) {
            for (auto j = item.begin(); j != item.end(); j++) {
                if (j == item.end() - 1) {
                    cout << *j;
                } else {
                    cout << *j << ' ';
                }
            }
            cout << endl;
        }

    }

    return 0;
}