#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int sum;
    for(int i=0;i<m;i++){
        sum+=ans[i];
    }
    for(int i=0;i<=n-m;i++){
        int t=0;
        for(int k=i;k<=i+m-1;k++){
            t+=ans[k];
        }
        if(sum>t){
            sum=t;
        }
    }
    cout<<sum;
    return 0;
}