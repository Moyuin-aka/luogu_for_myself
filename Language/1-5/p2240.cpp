#include<bits/stdc++.h>
using namespace std;
struct coin{
    int weight;
    double value;
    double per;
};
int main(){
    int n,t;
    cin>>n>>t;
    vector<coin>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i].weight>>coins[i].value;
        coins[i].per=coins[i].value/coins[i].weight;
    }
    sort(coins.begin(),coins.end(),[](const auto &a,const auto &b){
        return a.per>b.per;
    });
    double takeaway=0;
    int takeweight=0;
    for(int i=0;i<n;i++){
        
        if(takeweight+coins[i].weight<=t){
            takeaway+=coins[i].value;
            takeweight+=coins[i].weight;
        }
        else{
        while(takeweight<t){
            takeaway+=coins[i].per;
            //我感觉这里容易tle，待会换个算法
            takeweight++;
            }
        }
    }
    cout<<fixed<<setprecision(2)<<takeaway<<endl;
    return 0;
}