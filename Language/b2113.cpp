#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string newS = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            newS += char(s[i] + s[0]);
            break;
        }
        newS += char(s[i] + s[i + 1]);
    }
    cout<<  newS;
    return 0;
}