#include<iostream>
using namespace std;
int one(int a){
    return (a+5)*3;
}
int two(int a){
    return a*3+5;
}
int main(){
    int a;
    cin>>a;
    cout<<one(a)<<" "<<two(a);
    return 0;
}