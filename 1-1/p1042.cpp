#include <bits/stdc++.h>
using namespace std;
void eleven(string s)
{
    long long w=0, l = 0;
    for (char c : s)
    {
        if (c == 'W')
            w++;
        else
            l++;
        if ((w >= 11 || l >= 11) && abs(w - l) >= 2)
        {
            cout << w << ':' << l << endl;
            w = 0, l = 0;
        }
    }
    cout << w << ':' << l << endl;
}
void twenty_one(string s)
{
    long long w=0, l = 0;
    for (char c : s)
    {
        if (c == 'W')
            w++;
        else
            l++;
        if ((w >= 21 || l >= 21) && abs(w - l) >= 2)
        {
            cout << w << ':' << l << endl;
            w = 0, l = 0;
        }
    }
    cout << w << ':' << l << endl;
}
string s;
int main()
{
    char i;
    while (cin >> i && i != 'E')
    {
        s += i;
    }
    eleven(s);
    cout << endl;
    twenty_one(s);
    return 0;
}