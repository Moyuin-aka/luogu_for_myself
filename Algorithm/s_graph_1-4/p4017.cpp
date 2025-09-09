#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

typedef long long ll;
using namespace std;
// 其实是一个有向图无环做拓扑排序，最大食物链表示判断排序数，很经典的题型

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>indegree(n+1,0);
    vector<ll>out(n+1,0);
    vector<vector<ll>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int A,B;
        cin>>A>>B;
        indegree[B]++;
        out[A]++;
        adj[A].push_back(B);
    }
    const int MOD = 80112002;
    vector<ll> dp(n + 1, 0);

    // Kahn 拓扑 + 路径计数：入度为 0 的点作为源点，dp=1
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (ll v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (--indegree[v] == 0) q.push((int)v);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(out[i]==0) ans = (ans + dp[i]) % MOD;
    }
    cout<<ans;
    return 0;
}