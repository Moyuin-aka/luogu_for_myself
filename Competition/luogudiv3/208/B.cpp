#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<int>sakura(n);
        for(ll i=0;i<n;i++) cin>>sakura[i];
        ll sum=0;
        if(k%2==0&&k!=0) {
            if(n!=2){
            sort(sakura.begin(),sakura.end());
            reverse(sakura.begin(),sakura.end());
            sum=sakura[0]*n;
            }
            else{
                if(sakura[0]<sakura[1]) sum=sakura[0]+sakura[1];
                else sum=sakura[0]*n;
            }
        }
        else if(k%2!=0){
            if(n!=2){
            sort(sakura.begin(),sakura.end());
            reverse(sakura.begin(),sakura.end());
            sum=sakura[0]*n;
            }
            else{
                if(sakura[0]>sakura[1]) sum=sakura[0]+sakura[1];
                else sum=sakura[1]*n;
            }
        }
        else if(k==0){
            int temp=0;
            for(ll j=0;j<n;j++){
                if(sakura[j]>temp) temp=sakura[j];
                sum+=temp;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}