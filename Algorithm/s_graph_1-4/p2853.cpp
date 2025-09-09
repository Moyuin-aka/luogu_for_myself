#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int u,vector<vector<int>>&adj,vector<int>&cnt,vector<bool>&visited){
    // 这个 visited 是“本轮（某一头奶牛）的全局访问标记”，不要在回溯时清除，否则会把同一结点按多条路径重复计数
    visited[u]=true;
    cnt[u]++;
    for(int v:adj[u]){
        if(!visited[v]) dfs(v,adj,cnt,visited);
    }
}
int main(){
    int k,n,m;
    cin>>k>>n>>m;
    //对每一头牛所在的点做dfs维护cnt标记，最后判断哪个农场的cnt 标记达到了K个
    vector<vector<int>>adj(n+1);
    vector<int>cnt(n+1,0);
    vector<int>pos(k);
    for(int i=0;i<k;i++) cin>>pos[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }// 单向图
    for(int i=0;i<k;i++){
        vector<bool>visited(n+1,false);
        dfs(pos[i],adj,cnt,visited);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==k) ans++;
    }
    cout<<ans;
    return 0;
}