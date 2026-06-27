#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // 区间和计算
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int m;
    cin>>m;//区间数
    vector<pair<int,int>> q(m);
    for(int i=0;i<m;++i){
        cin>>q[i].first>>q[i].second;
    }
    // 先暴力写法：时间复杂度为O(n*m)
    // 后续可以考虑前缀和优化
    /*for(int i=0;i<m;++i){
        int l=q[i].first,r=q[i].second;
        long long sum=0;
        for(int j=l;j<=r;++j){
            sum+=a[j];
        }
        cout<<sum<<"\n";
    }*/

    // 前缀和优化,时间复杂度为O(n+m)
    vector<long long>pre(n+1,0);// pre[i]表示a[1]到a[i]的和
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    for(int i=0;i<m;i++){
        int l=q[i].first,r=q[i].second;
        cout<<pre[r]-pre[l-1]<<endl; //这里选择l-1是因为 pre[l]表示a[1]到a[l]的和，不能减去的时候把a[l]也减去了
    }


    return 0;
}