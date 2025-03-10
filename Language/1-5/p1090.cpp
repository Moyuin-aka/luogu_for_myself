#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<ll>stack(n);
    for(int i=0;i<n;i++){
        cin>>stack[i];
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    sort(stack.begin(),stack.end());

    ll cost=0;
    
    while(stack.size()>1){
        ll temp=stack[0]+stack[1];
        cost+=temp;
        stack.erase(stack.begin());
        stack[0]=temp;
        sort(stack.begin(),stack.end());
    }
    cout<<cost<<endl;
    return 0;
}