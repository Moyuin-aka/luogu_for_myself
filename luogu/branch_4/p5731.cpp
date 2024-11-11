#include <bits/stdc++.h>
using namespace std;
int n;
int num[10][10];
int main()
{
    cin >> n;
    num[1][1]=1;
    for (int i = 1, j = 1, tot = 1; tot < n * n;)
    { // 一直填到n*n个数填完
        while (++j <= n && !num[i][j])
            num[i][j] = ++tot;
            --j; // 向右
        while (++i <= n && !num[i][j])
            num[i][j] = ++tot;
            --i; // 向下
        while (--j > 0 && !num[i][j])
            num[i][j] = ++tot;
            ++j; // 向左
        while (--i > 0 && !num[i][j])
            num[i][j] = ++tot;
            ++i; // 向上
    }
    for (int i = 1; i <= n; ++i, cout << endl)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << setw(3) << num[i][j];
        }
    }
    return 0;
}