#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    int count=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        bool yes rue;
        for(int j=i+1;j<n;j++){
            if(arr[i]<=arr[j]){
                yes=false;
            }
        }
        if(yes){
            count++;
        }
    }
    cout<<count;
}