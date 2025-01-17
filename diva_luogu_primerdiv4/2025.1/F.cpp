#include <bits/stdc++.h>
using namespace std;
struct Sum
{
    int sum = 0;
    int id;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ma(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ma[i][j];
        }
    }
    vector<Sum> sum(m);
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j].sum += ma[i][j];
        }
        sum[j].id = j + 1;
    }
    sort(sum.begin(), sum.end(), [](const Sum &a, const Sum &b)
         {
        if(a.sum==b.sum) return a.id>b.id;
        return a.sum>b.sum; });
    int index = sum[0].id - 1;
    int p = 0;
    auto maxi = max_element(ma.begin(), ma.end(), [index](const vector<int> &row1, const vector<int> &row2)
                            { return row1[index] < row2[index]; });
    int value = (*maxi)[index];
    for (int i = 0; i < n; i++)
    {
        if (ma[i][index] == value)
            p++;
    }
    cout << value << " " << p << endl;
}