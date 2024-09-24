#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float m,t,s,l;
    cin>>m>>t>>s;
    if(s==0){
        l=m;
    }
    else{
    l=m-(ceil(s/t));
    if(l<=0){
        l=0;
    }
    }
    cout<<l;
    return 0;
}