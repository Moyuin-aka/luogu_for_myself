#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> stu(n, 0);
    int a;
    cin >> a;
    while (a--)
    {
        int x;
        cin >> x;
        stu[x - 1]++;
    }
    int b;
    cin >> b;
    while (b--)
    {
        int y;
        cin >> y;
        stu[y - 1]++;
    }
    int c;
    cin >> c;
    while (c--)
    {
        int z;
        cin >> z;
        stu[z - 1]++;
    }
    int bad=0;
    for(int t:stu){
        if(t!=1) bad++;
    }
    cout<<bad<<endl;
    return 0;
}