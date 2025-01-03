#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long cal(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    vector<long long>dp(n,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    long long count=cal(n);
    cout<<count<<endl;
    return 0;
}