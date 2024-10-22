#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long S=0;
    long long f=1;
    for(int i=1;i<=n;i++){
        f*=i;
        S+=f;
    }
    cout<<S;
    return 0;
    }
