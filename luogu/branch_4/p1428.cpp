#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nas[n];
    for(int i=0;i<n;i++){
        cin>>nas[i];
    }
    cout<<0<<" ";
    for(int i=1;i<n;i++){
        int count=0;
        int temp=i-1;
        while(temp>=0){
            if(nas[i]>nas[temp]){
                count++;
            }
            temp--;
        }
        cout<<count<<" ";
        }
        return 0;
    }

