#include <bits/stdc++.h>
using namespace std;
bool cj(char n)
{
    if (n == '*')
    {
        return false;
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    char map[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '?')
            {
                map[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '*')
            {
                if (i - 1 >= 0)
                {
                    if (cj(map[i - 1][j]))
                        map[i - 1][j]++;
                    if (j - 1 >= 0)
                        if (cj(map[i - 1][j - 1]))
                            map[i - 1][j - 1]++;
                    if (j + 1 < m)
                        if (cj(map[i - 1][j + 1]))
                            map[i - 1][j + 1]++;
                }
                if (i + 1 < n)
                {
                    if (cj(map[i + 1][j]))
                        map[i + 1][j]++;
                    if (j - 1 >= 0)
                        if (cj(map[i + 1][j - 1]))
                            map[i + 1][j - 1]++;
                    if (j + 1 < m)
                        if (cj(map[i + 1][j + 1]))
                            map[i + 1][j + 1]++;
                }
                if (j - 1 >= 0)
                {
                    if (cj(map[i][j - 1]))
                        map[i][j - 1]++;
                }
                if (j + 1 < m)
                {
                    if (cj(map[i][j + 1]))
                        map[i][j + 1]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}