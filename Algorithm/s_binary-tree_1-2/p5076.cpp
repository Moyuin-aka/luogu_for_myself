#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 2147483647
#define Min -2147483647

// 线性表的时间复杂度很高，我们可以用树来维护，在STL里面本身自带set，可以用一下
// 这里给2个写法，第一种是线性表，第二种是set，线性表过不了最后一个检测点，set可以过

void opsLinear(int op, int x, vector<ll> &num);
void opsSet(int op, int x, set<ll> &num);
// void opsMap(int op, int x, map<ll, int> &num);
// set能做的题可以改为map，而且map在统计数字频率方面更加有优势，不过这里用不到

int main()
{
    int q;
    cin >> q;
    // vector<ll> num;
    set<ll> num;
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        opsSet(op, x, num);
    }
    return 0;
}

void opsLinear(int op, int x, vector<ll> &num)
{
    // 看上去像是写一个可自动排序表的数据结构，就像每次插入一个数据后sort一下
    // 但其实可以当作是一个树结构？先试试直接的线性表吧，插入一个数据后sort一下，看看会不会超时
    if (op == 1)
    {
        // 查询操作
        int index = 1;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] < x)
            {
                index++;
            }
        }
        cout << index << endl;
    }
    else if (op == 2)
    {
        sort(num.begin(), num.end());
        // 查询排名操作
        int index = x - 1;
        cout << num[index] << endl;
    }
    else if (op == 3)
    {
        ll minn = Min;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] < x && num[i] > minn)
            {
                minn = num[i];
            }
        }
        cout << minn << endl;
    }

    else if (op == 4)
    {
        ll maxn = Max;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] > x && num[i] < maxn)
            {
                maxn = num[i];
            }
        }
        cout << maxn << endl;
    }
    else
    {
        // 插入操作
        num.push_back(x);
        sort(num.begin(), num.end());
    }
}
/* - - - - - - - - - - */

void opsSet(int op, int x, set<ll> &num)
{
    if (op == 1)
    {
        // 计算小于x的元素个数+1，不能直接去靠set的有序性去find(x)找距离，因为set如果find不了元素会返回end()，而end()是一个迭代器，不能直接用来计算距离
        int rank = 1;
        for (auto val : num)
        {
            if (val < x)
                rank++;
        }
        cout << rank << endl;
        // 当然set去利用lower_bound也可以，直接返回第一个小于等于x的元素的迭代器，然后计算距离就行了
        // auto it=num.lower_bound(x);
        // cout<<distance(num.begin(),it)+1<<endl;
    }
    else if (op == 2)
    {
        // 找到第x个数
        auto it = num.begin();
        advance(it, x - 1); // 移动迭代器到第x个位置
        cout << *it << endl;
    }
    else if (op == 3)
    {
        // 找到小于x的最大值，一个道理，如果find不到x，返回end()，如果找到x，返回x的前一个元素
        // lower_bound返回第一个小于等于x的元素
        auto it = num.lower_bound(x);
        if (it == num.begin())
        {
            cout << Min << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
        }
    }
    else if (op == 4)
    {
        auto it = num.upper_bound(x);
        // upper_bound返回第一个大于x的元素

        if (it == num.end())
        {
            cout << Max << endl;
        }
        else
        {
            cout << *it << endl;
        }
    }
    else
    {
        num.insert(x);
    }
}