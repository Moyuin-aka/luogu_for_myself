#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;
    vector<int> dp(T + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int time, value;
        cin >> time >> value;
        for (int j = T; j >= time; j--)
        {
            dp[j] = max(dp[j], dp[j - time] + value);
        }
    }
    cout << dp[T] << endl;
}

// 不是贪心，不能平均化
/*struct med{
    double time;
    double value;
    double perValue;
};
int main()
{
    int T,M;//总时间，总数目
    cin>>T>>M;
    vector<med>herb(M);
    for(int i=0;i<M;i++){
        cin>>herb[i].time>>herb[i].value;
        herb[i].perValue=herb[i].value/herb[i].time;
    }
    sort(herb.begin(),herb.end(),[](const med&a,const med&b){
        return a.perValue>b.perValue;
    });
    int total=0;
    int time=0;
    while(time<T){
        total
    }
}*/