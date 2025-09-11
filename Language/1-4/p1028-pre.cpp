#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 只有一个数 n 的数列是一个合法的数列。
    // 在一个合法的数列的末尾加入一个正整数，但是这个正整数不能超过该数列最后一项的一半，可以得到一个新的合法数列。
    int n;
    cin>>n;
    vector<ll>dp(n+1,0); //以i开头的合法序列数 dp[i] = 1 + \sum_{j=1}^{\lfloor i/2 \rfloor} dp[j]
    dp[1]=1;
    vector<ll>prefix_sum(n+1,0); // prefix_sum[i] = dp[1] + dp[2] + ... + dp[i]
    prefix_sum[1] = dp[1];
    for(int i=2;i<=n;i++){
        dp[i]=1 + prefix_sum[i/2];
        prefix_sum[i] = prefix_sum[i-1] + dp[i];
    }
    // 算法优化，前缀和将时间复杂度降为O(n)
    cout<<dp[n];
    return 0;

}