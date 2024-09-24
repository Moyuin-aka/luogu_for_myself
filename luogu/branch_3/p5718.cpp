#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[n];
    for(int i=0;i<n;i++){
        int n;
        cin>>n;
        ans[i]=n;
    }
    int minval=*min_element(ans,ans+n);
    cout<<minval;
    return 0;
}