#include<iostream>
using namespace std;
#include<string>
int main(){
    string a;
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]<='z'&&a[i]>='a'){
            a[i]+='A'-'a';
        }
    }
    cout<<a;
}