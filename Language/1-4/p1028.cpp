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
    for(int i=2;i<=n;i++){
        dp[i]=1;
       for(int j=1;j<=i/2;j++){
            dp[i]+=dp[j];// j<=i/2, dp[j]表示以j开头的合法序列数,相当于在i的基础上加上j
       }
       // 对不同的 j，这些集合是互不相交的（第二项不一样），所以把各个 dp[j] 相加不会重叠。

    }
    cout<<dp[n];
    return 0;

}