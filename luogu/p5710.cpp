#include<iostream>
using namespace std;
int main(){
    int x,A,B,C,D;
    cin>>x;
    if((x%2==0)&&(x>4)&&(12>=x)){
        A=1,B=1,C=0,D=0;}
    else if((x%2==0)||(x>4)&&(12>=x)){
        A=0,B=1,C=1,D=0;
    }
    else{
        A=0,B=0,C=0,D=1;
    }
    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    return 0;
    
}