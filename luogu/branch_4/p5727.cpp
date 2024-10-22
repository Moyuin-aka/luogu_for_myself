#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ans;
    int n;
    cin>>n;
    ans.push_back(n);
    while(n!=1){
        if(n%2!=0){
            n=n*3+1;
        }
        else{
            n/=2;
        }
        ans.push_back(n);
    }
    reverse(ans.begin(),ans.end());
    for(int n:ans){
        cout<<n<<" ";
    }
    return 0;
}