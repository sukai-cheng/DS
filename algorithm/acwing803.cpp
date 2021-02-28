#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
vector<PII> section;
vector<int> edge;
int Left = 2e9;
int Right = -2e9;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        section.push_back(PII(l, r));
        edge.push_back(l);
    }

    int tmp = section.size();
    sort(section.begin(), section.end());

    for (auto item : section) {

        if(item.first <= Right && item.second > Right){
            Right = item.second;
            tmp--;
        }else if(item.first > Right){
            Left = item.first;
            Right = item.second;
        }else if(item.first >= Left && item.second <= Right){
            tmp--;
        }
    }

    cout << tmp;
    return 0;
}