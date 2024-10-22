#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    sort(ans.begin(),ans.end());
    cout<<ans[n-1]-ans[0];
    return 0;

}