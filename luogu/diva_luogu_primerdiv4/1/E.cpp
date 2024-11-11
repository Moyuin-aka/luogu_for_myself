#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prime(int x){
    if(x<=2){
        return true;
    }
    for(int i=2;i<x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m,r,k;
    cin>>n>>m>>r>>k;
    int time=0;
    vector<int>ans(100);
    for(int i=0;i<n;i++){
        int x= (i*m+r)                                                  ;
        if(prime(x)&&x<=n){
            time++;
            ans.push_back(x);
        }
    }
    if(time<k){
        cout<<-1;
        return 0;
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans[k-1];
    return 0;
}