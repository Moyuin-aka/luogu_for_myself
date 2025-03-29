#include <bits/stdc++.h>
using namespace std;
struct node
{
    int power;
    int id;
};
int main()
{
    // 很典型的二叉树逻辑，从底端一直到根节点，逐层向上遍历，不过也可以用模拟解决它
    // 每一层的节点数是2^i，i从0开始，直到n-1
    int n;
    cin >> n;
    vector<node> country(pow(2, n));
    for (int i = 0; i < pow(2, n); i++)
    {
        cin >> country[i].power;
        country[i].id = i + 1;
    }
    // 通过比较能力值来决定谁是父节点，id相邻的打比赛，一直打比赛，直到留下最后一组，看看最后一组谁输了谁就是亚军，然后输出亚军的id即可
    vector<node> b;
    while (country.size() > 2)//这个思路很好...
    {
        for (int i = 0; i < country.size(); i += 2)
        {
            //cout<<country[i].power<<" "<<country[i + 1].power<<endl;
            if (country[i].power > country[i + 1].power)
            {
                b.push_back(country[i]);
            }
            else
            {
                b.push_back(country[i + 1]);
            }
        }
        country = b;
        b.clear();
    }
    if (country[0].power > country[1].power)
    {
        cout << country[1].id << endl;
    }
    else
    {
        cout << country[0].id << endl;
    }
    return 0;
}
