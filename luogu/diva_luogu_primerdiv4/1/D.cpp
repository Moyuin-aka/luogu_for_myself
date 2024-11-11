#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    n*=2;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    for(int j=0;j<n;j++){
        int temp=ans[j];
        if(j+1!=ans[temp-1]||j+1==temp){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
    
}