#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<unsigned long long>ans;
    for(int i=0;;i++){
        unsigned long long n;
        cin>>n;
        ans.push_back(n);
        if(ans[i]==0){
            break;
        }
    }
    ans.erase(min_element(ans.begin(),ans.end()));
    reverse(ans.begin(),ans.end());
    for(int n:ans){
        cout<<n<<" ";
    }
    return 0;
    
}