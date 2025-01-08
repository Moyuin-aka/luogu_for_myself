#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int times = 0;
        int n;
        cin >> n;
        vector<int> line(n);
        vector<int> check(n);
        bool same = false;
        for (int i = 0; i < n; i++)
        {
            cin >> line[i];
            check[i] = line[i];
        }
        sort(check.begin(), check.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (check[i] == check[i + 1])
            {
                same = true;
                if (line[0] == check[i] || line[n - 1] == check[i])
                {
                    times = 2;
                    if (line[n - 1] == check[i] && line[0] == check[i])
                    {
                        times = 1;
                    }
                    break;
                }
                else
                {
                    times = 3;
                }
            }
        }
        if (!same)
        {
            times = n;
        }
        cout << times << endl;
    }
}