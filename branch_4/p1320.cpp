#include <bits/stdc++.h>
using namespace std;
vector<int> s;
string line;
int main()
{
    int N = 0;
    while (getline(cin, line))
    {
        for (char ch : line)
        {
            s.push_back(ch-'0');
        }
        N++;
        if (N == line.size())
        {
            break;
        }
    }
    cout << N << " ";
    int temp = 0;
    int count = 0;
    for (int n : s)
    {
        if (n != temp)
        {
            cout << count << " ";
            temp = n;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    cout << count;
    return 0;
}