#include <iostream>

using namespace std;
/*
top:0 1
down:0 -1
left:-1 0
right:1 0
 5 6
* * # # # #
# * * # # #
# # * * # #
# # # * * #
# # # # * *
4 5
*/

const int maxn = 500;
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char map[maxn][maxn];
int flag[maxn][maxn];
int edx, edy;


bool check(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] == '*' && flag[x][y] == 0) {
        return true;
    }
    return false;
}

bool dfs(int x, int y) {
    if (!check(x, y)) {
        return false;
    }
    if (x == edx && y == edy) {
        return true;
    }
    flag[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (dfs(x + dx[i], y + dy[i])) {
            return true;
        }
    }
    return false;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cin >> edx >> edy;

    dfs(0, 0);

    return 0;
}