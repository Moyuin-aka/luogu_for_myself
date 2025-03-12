#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<unordered_map<int, int>> boxes(n);
    while (q--) {
        int num;
        cin >> num;
        if (num == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            int idx = i - 1;
            boxes[idx][j] = k;
        } else if (num == 2) {
            int i, j;
            cin >> i >> j;
            int idx = i - 1;
            cout << boxes[idx][j] << endl;
        }
    }
    return 0;
}