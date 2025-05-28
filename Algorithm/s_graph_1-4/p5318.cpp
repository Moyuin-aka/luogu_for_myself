/*洛谷p5318 简单的建立图，DFS，BFS的基本操作s*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int u, const vector<vector<int>> &g, bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    for (int v : g[u])
    {
        if (!visited[v])
            dfs(v, g, visited);
    }
}
void bfs(int start, const vector<vector<int>> &g, bool visited[])
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : g[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m; // 点，边
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    bool visited[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // 建立的是有向图，这里控制是从u到v
        g[u].push_back(v);
    }
    for (int i = 0; i <= n; i++)
    {
        sort(g[i].begin(),g[i].end());
        visited[i] = false;
    }

    dfs(1, g, visited);
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    cout << endl;
    bfs(1, g, visited);
    return 0;
}