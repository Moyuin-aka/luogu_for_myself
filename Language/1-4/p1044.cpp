#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
typedef long long ll;
// 经典判断栈序列数目的问题
ll count(int n){
    ll res=1;
    vector<ll>dp(n+1,0); // dp[i]表示i个节点的栈序列数
    // 卡特兰数
    // dp[i]=sum(dp[j]*dp[i-1-j]) j=0~i-1
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<count(n)<<"\n";
    
    return 0;
}
