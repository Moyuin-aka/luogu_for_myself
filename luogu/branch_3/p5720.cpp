#include<iostream>
using namespace std;
int main(){
    int a,i=0;
    cin>>a;
    while(a>=1){
        a/=2;
        i++;
    }
    cout<<i;
    return 0;
}