#include<bits/stdc++.h>
using namespace std;
int main(){
    int type;
    cin>>type;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(type==0){
        cout<<a+b;
        return 0;
    }
    else{
        cout<<max(a-c )+max(b-d,0);
        return 0;

    }
}