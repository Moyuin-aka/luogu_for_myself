#include <bits/stdc++.h>
using namespace std;

int main()
{
    int line;
    cin >> line;
    vector<vector<int>> dp(line);
    for (int i = 1; i <= line; i++)
    {
        dp[i - 1].resize(i);
        for (int j = 0; j < i; j++)
        {
            cin >> dp[i - 1][j];
        }
    }
    // 记录底层size，从下往上加
    for (int i = line - 2; i >= 0; i--)
    { // 最底层的上一层为line-2
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
}