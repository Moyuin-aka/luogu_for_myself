#include<bits/stdc++.h>
using namespace std;
int ans[26];
bool prime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    string a;
    cin>>a;
    int tempmin=INT_MAX;
    int tempmax=0;
    int len=a.size();
    for(int i=0;i<len;i++){
        ans[a[i]-'a']++;
        }
        for(int n:ans){
            if(n!=0){
            tempmax=max(tempmax,n);
            tempmin=min(tempmin,n);
            }
        }
    bool judge=prime(tempmax-tempmin);
    if(judge){
        cout<<"Lucky Word"<<endl<<tempmax-tempmin;
    }
    else{
        cout<<"No Answer"<<endl<<0;
    }
    return 0;
}