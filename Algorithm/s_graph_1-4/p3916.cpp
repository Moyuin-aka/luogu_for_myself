/*# P3916 图的遍历 */
#include <iostream>
#include <vector>
// 做DFS遍历，每次输出最大值就好
using namespace std;
//但是正向图的话每次清零遍历要爆炸，我们可以使用反向图，从n到1进行处理，每次保留最大的（往往是最后的那一个）
//用数组存储最大值最后遍历，不用重复DFS？
vector<vector<int>>rev_g;
vector<int>ans;
vector<bool>visited_fin;

void dfs(int u,int begin){
    //u是当前节点，begin是发起dfs的节点，也是要给ans的值
    visited_fin[u]=true;
    ans[u]=begin;
    for(int v:rev_g[u]){
        if(!visited_fin[v]) dfs(v,begin);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    rev_g.resize(n+1);
    visited_fin.resize(n+1,false);
    ans.resize(n+1);
    while(m--){
        int u,v;
        cin>>u>>v;//注意是反向图
        rev_g[v].push_back(u);
    }

    //从最后点向下到1进行处理
    for(int i=n;i>=1;i--){
        if(!visited_fin[i]) dfs(i,i);
    }
    for(int i:ans) cout<<i<<" ";
    return 0;
}
/*int maxn = -1;
void dfs(int u, const vector<vector<int>> g, vector<bool> &visited)
{
    visited[u] = true;
    if (u > maxn)
        maxn = u;
    for (int v : g[u])
    {
        if (!visited[v])
            dfs(v, g, visited);
    }
}

int main()
{
    // 先建图
    int n, m;
    cin >> n >> m; // 点，边，单向图
    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, g, visited);
        cout << maxn << " ";
        maxn = -1;
        for (int i = 0; i <= n; i++)
            visited[i] = false;
    
    }
    return 0;
}
*/
/*

## 题目描述

给出 $N$ 个点，$M$ 条边的有向图，对于每个点 $v$，令 $A(v)$ 表示从点 $v$ 出发，能到达的编号最大的点。现在请求出 $A(1),A(2),\dots,A(N)$ 的值。

## 输入格式

第 $1$ 行 $2$ 个整数 $N,M$，表示点数和边数。

接下来 $M$ 行，每行 $2$ 个整数 $U_i,V_i$，表示边 $(U_i,V_i)$。点用 $1,2,\dots,N$ 编号。

## 输出格式

一行 $N$ 个整数 $A(1),A(2),\dots,A(N)$。

## 输入输出样例 #1

### 输入 #1

```
4 3
1 2
2 4
4 3
```

### 输出 #1

```
4 4 3 4
```

## 说明/提示

- 对于 $60\%$ 的数据，$1 \leq N,M \leq 10^3$。
- 对于 $100\%$ 的数据，$1 \leq N,M \leq 10^5$。*/