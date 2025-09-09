#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1); //邻接表，pair的first代表邻接点，second代表边权
    for(int i=0;i<m;i++){
        int u,v,w; //w代表边权
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    //找到1到n到最长路，输出边权总值
    vector<int>dist(n+1,-INT16_MAX); //dist[i]表示从1到i的最长路
    dist[1]=0;
    for(int i=1;i<=n;i++){
        if(dist[i]!=-INT16_MAX){ //如果i不可达，就不更新它的邻接点
            for(auto p:adj[i]){
                int v=p.first,w=p.second;
                dist[v]=max(dist[v],dist[i]+w);
            }
        }
    }
    cout<<(dist[n]==-INT16_MAX?-1:dist[n])<<endl;
    return 0;
}
    