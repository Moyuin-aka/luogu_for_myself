#include<iostream>
using namespace std;
int main(){
    int y,m,d;
    cin>>y>>m;
    if(m==4||m==6||m==9||m==11){
        d=30;
    }
    else if(m==2){
        if(y%400==0||(y%4==0&&y%100!=0)){
            d=29;
        }
        else{
            d=28;
        }
    }
    else{
        d=31;
    }
    cout<<d<<endl;
    return 0;
}