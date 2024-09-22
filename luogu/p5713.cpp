#include<iostream>
using namespace std;
int main(){
    int n,local,luogu;
    cin>>n;
    local=5*n;
    luogu=3*n+11;
    if(local>luogu){
        cout<<"Luogu"<<endl;
    }
    else{
        cout<<"Local"<<endl;
        return 0;
    }

}