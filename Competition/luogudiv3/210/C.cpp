#include <bits/stdc++.h>
using namespace std;
string getMax(const string &s)
{
    string result;
    for (char c : s)
    {
        while (!result.empty() && result.back() < c && result.size() + s.size() > s.size())
        {
            result.pop_back();
        }
        result.push_back(c);
    }
    return result;
}

string getMinChar(int n, int k, const string &s)
{
    vector<vector<string>> dp(n + 1, vector<string>(k + 1, ""));

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = getMax(s.substr(0, i));
    }

    for (int j = 2; j <= k; j++)
    {
        for (int i = j; i <= n; i++)
        {
            for (int p = j - 1; p < i; p++)
            {
                string maxStr = getMax(s.substr(p, i - p));
                string maxChar = max(dp[p][j - 1], maxStr);
                if (dp[i][j].empty() || maxChar < dp[i][j])
                {
                    dp[i][j] = maxChar;
                }
            }
        }
    }
    return dp[n][k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n; // n为字符串的总长度，k为最后的分段的字符串数字
    cin >> n >> k;
    string S;
    cin >> S;
    // 贪心找最小分割，然后把ascll码最大的字符输出
    cout << getMinChar(n, k, S) << endl;
}