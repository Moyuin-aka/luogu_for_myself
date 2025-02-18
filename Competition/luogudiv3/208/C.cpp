#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int time=0;
        ll k;
        long double r;
        cin>>k;
        if(k%2!=0){
            cout<<1<<endl;
            continue;
        }
        r=k+0.5;
        bool loop=false;
        while(true){
            ll temp=(r*2)/2+1;
            double judgetemp=r;
            r=r*temp;
            cout<<r<<endl;
            time++;
            if(static_cast<ll>(r)==r) break;
            if(judgetemp==r){
                loop=true;
                break;
            }
            
        }
        if(!loop)
        cout<<time<<endl;
        else cout<<"NO!"<<endl;
        //cout<<r<<endl;
    }
}