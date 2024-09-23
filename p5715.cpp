#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(b>c){
            cout<<c<<" "<<b<<" "<<a<<endl;
        }
        else if(c>a){
            cout<<b<<" "<<a<<" "<<c<<endl;
        }
        else{
            cout<<b<<' '<<c<<' '<<a<<endl;
        }
    }
    else if(a<=b){
        if(a>c){
            cout<<c<<' '<<a<<' '<<b<<endl;
            }
        else if(c>a&c<b){
            cout<<a<<' '<<c<<' '<<b<<endl;
        }
        else if(c>b){
            cout<<a<<' '<<b<<' '<<c<<endl;
        }
        else{
            cout<<a<<' '<<c<<' '<<b<<endl;
        
        }
    }
    
    return 0;
}