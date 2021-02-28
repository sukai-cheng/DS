#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> V, int target) {
    int l = 0, r = V.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (V[mid] <= target) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int target;
    cin >> target;
    vector<int> vec = {35, 12, 10, 8, 7, 3};
    cout << binarySearch(vec, target);
}

