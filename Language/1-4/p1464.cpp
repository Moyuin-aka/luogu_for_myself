#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

// 递归函数，但是先暴力写一下
ll work(ll a,ll b,ll c){
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return work(20,20,20);
    if(a<b&&b<c) return work(a,b,c-1)+work(a,b-1,c-1)-work(a,b-1,c);
    else return work(a-1,b,c)+work(a-1,b-1,c)+work(a-1,b,c-1)-work(a-1,b-1,c-1);
}
//ll dp[21][21][21];
vector<vector<vector<ll>>> dp(21,vector<vector<ll>>(21,vector<ll>(21,-1)));
//可以看到递归中有大量重复计算，用记忆化搜索优化,三维数组，dp存储计算过的W(a,b,c),仅限于20以内也算优化了
ll work_up(ll a,ll b,ll c,vector<vector<vector<ll>>>&dp){
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return work_up(20,20,20,dp);
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    if(a<b&&b<c) dp[a][b][c] = work_up(a,b,c-1,dp)+work_up(a,b-1,c-1,dp)-work_up(a,b-1,c,dp);
    else dp[a][b][c] = work_up(a-1,b,c,dp)+work_up(a-1,b-1,c,dp)+work_up(a-1,b,c-1,dp)-work_up(a-1,b-1,c-1,dp);
    return dp[a][b][c];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c;
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<work_up(a,b,c,dp)<<"\n";
    }
    return 0;
}