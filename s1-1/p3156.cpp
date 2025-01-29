#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>person(n);
    for(ll i=0;i<n;i++){
        cin>>person[i];
    }
    for(ll i=0;i<m;i++){
        ll t;
        cin>>t;
        cout<<person[t-1]<<endl;
    }
    return 0;
}