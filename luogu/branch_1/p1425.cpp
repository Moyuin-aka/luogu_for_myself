#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f;
    if(b<=d){
        f=d-b;
        e=c-a;
        cout<<e<<' '<<f<<endl;
        }
        else{
            f=d-b+60;
            e=c-a-1;
            cout<<e<<' '<<f<<endl;
        }
    return 0;
    
}
