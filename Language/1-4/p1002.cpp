#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    // 从（0,0)向下向右走到达(n,m)的路径数
    // 有不能走的点，考虑dp
    // 卒行走的规则：可以向下、或者向右
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>ban(9);
    cin>>ban[0].first>>ban[0].second;//(x,y)
    // 读入不能走的点,日字型
    ban[1]={ban[0].first+2,ban[0].second+1};
    ban[2]={ban[0].first+2,ban[0].second-1};
    ban[3]={ban[0].first-2,ban[0].second+1};
    ban[4]={ban[0].first-2,ban[0].second-1};
    ban[5]={ban[0].first+1,ban[0].second+2};
    ban[6]={ban[0].first+1,ban[0].second-2};
    ban[7]={ban[0].first-1,ban[0].second+2};
    ban[8]={ban[0].first-1,ban[0].second-2};
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));//dp[i][j]表示到达(i,j)的路径数
    dp[0][0]=(find(ban.begin(),ban.end(),make_pair(0,0))==ban.end())?1:0; // 起点

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0) continue;
            if(find(ban.begin(),ban.end(),make_pair(i,j))!=ban.end()){
                dp[i][j]=0; // 不能走的点
                continue;
            }
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i][j-1];
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n"; // debug
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;


}