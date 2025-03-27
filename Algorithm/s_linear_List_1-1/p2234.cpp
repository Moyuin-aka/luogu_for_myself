#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//循环遍历做非暴力的话，不如直接用set来做，自动排序的同时还可以自动找最相近值
//学习set的lower_bound和upper_bound函数
//set的lower_bound函数返回的是第一个小于等于x的值的迭代器，upper_bound函数返回的是第一个大于x的值的迭代器
int main()
{
    set<ll> s;
    int n;
    cin >> n;
    
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (s.empty())
        {
            s.insert(x);
            ans += x;
            continue;
        }
        auto it = s.lower_bound(x);
        ll diff1 = LLONG_MAX, diff2 = LLONG_MAX;
        if (it != s.end())
        {
            diff1 = llabs(x - *it);
        }
        if (it != s.begin())
        {
            it--;
            diff2 = llabs(x - *it);
        }
        ans += min(diff1, diff2);

        //cout << "now is : " << ans << endl;
        s.insert(x);
    }
    cout << ans << endl;
    return 0;
}
//注意一下题目说了有负数营业额...