#include <bits/stdc++.h>
using namespace std;

// 拓扑排序：
// 返回值：0 = 有环（矛盾）；1 = 无环但不唯一；2 = 唯一序
// 若返回 2，会在 order 中写入唯一序列
int topo(int n, const bool adj[26][26], const int indeg_in[26], string &order) {
    int indeg[26];
    memcpy(indeg, indeg_in, sizeof(indeg));
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

    order.clear();
    bool unique = true;

    for (int taken = 0; taken < n; ++taken) {
        if (q.empty()) return 0;              // 有环：没有入度为 0 的点
        if ((int)q.size() > 1) unique = false; // 分支 >1：不是唯一序
        int u = q.front(); q.pop();
        order.push_back(char('A' + u));
        for (int v = 0; v < n; ++v) {
            if (adj[u][v]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
    }
    return unique ? 2 : 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    bool adj[26][26] = {};
    int indeg[26] = {};
    string rel, order;
    bool decided = false;

    for (int i = 1; i <= m; ++i) {
        cin >> rel; // 形如 "A<B"
        int u = rel[0] - 'A';
        int v = rel[2] - 'A';
        // 避免重边影响入度
        if (!adj[u][v]) {
            adj[u][v] = true;
            ++indeg[v];
        }

        int res = topo(n, adj, indeg, order);
        if (res == 0) { // 矛盾
            cout << "Inconsistency found after " << i << " relations.\n";
            decided = true;
            break;
        } else if (res == 2) { // 唯一确定
            cout << "Sorted sequence determined after " << i << " relations: " << order << ".\n";
            decided = true;
            break;
        }
        // res == 1：尚未确定，继续读下一条关系
    }

    if (!decided) {
        cout << "Sorted sequence cannot be determined.\n";
    }
    return 0;
}