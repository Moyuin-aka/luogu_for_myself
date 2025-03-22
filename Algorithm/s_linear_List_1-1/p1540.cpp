#include <bits/stdc++.h>
using namespace std;
bool isinmemory(queue<int>&memory, int x)
{
    queue<int> temp = memory;
    while (!temp.empty())
    {
        if (temp.front() == x)
        {
            return true;
        }
        temp.pop();
    }
    return false;
}
int main()
{
    int m, n; // m为内存大小，n为文章长度
    cin >> m >> n;
    int cnt = 0;
    queue<int> memory;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (isinmemory(memory, x))
        {
            continue;
        }
        else
        {
            if (memory.empty())
            {
                memory.push(x);
                cnt++;
            }
            else
            {
                if (memory.size() < m)
                {
                    memory.push(x);
                    cnt++;
                }
                else
                {
                    memory.pop();
                    memory.push(x);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}