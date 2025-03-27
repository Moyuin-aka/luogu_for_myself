#include <bits/stdc++.h>
using namespace std;

bool legal(vector<int>& pushstr, vector<int>& popstr)
{
    stack<int> s;
    int j = 0;
    for (int i = 0; i < pushstr.size(); i++)
    {
        s.push(pushstr[i]);
        while (!s.empty() && s.top() == popstr[j])
        {
            //cerr << "栈顶：" << s.top() << " 当前出栈：" << popstr[j] << endl;
            s.pop();
            j++;
        }
        
    } // 不能输入完后再判断，因为可能有些元素在栈中还没出栈
    // 验证栈序列
    return s.empty();
}

int main()
{
    //system("chcp 65001");   
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int>pushstr(n), popstr(n);
        for (int i = 0; i < n; i++)
        {
            cin>> pushstr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> popstr[i];
        }
        if (legal(pushstr, popstr))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
//注意字符输入时的空格问题，不能用char，因为char会把空格当成结束符，导致输入错误
//好好用int和vector