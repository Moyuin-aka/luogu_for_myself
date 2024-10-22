#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,m;
    cin>>l>>m;
    int ans[l+1];
    for(int i=0;i<=l;i++){
        ans[i]=1;
    }
    for(int i=0;i<m;i++){
        int begin,end;
        cin>>begin>>end;
        for(int j=begin;j<=end;j++){
            ans[j]=0;
        }
    }
    int count=0;
    for(int n:ans){
        if(n==1){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;

}