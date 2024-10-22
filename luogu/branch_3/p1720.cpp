#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long fibonaci_1=1,fibonaci_2=1;
    long long goal;
    if(n>=3){
    for(int i=1;i<=n-2;i++){
        goal=fibonaci_1+fibonaci_2;
        fibonaci_1=fibonaci_2;
        fibonaci_2=goal;
    }
    }
    else if(n==0){
        cout<<fixed<<setprecision(2)<<0.00;
        return 0;
    }
    else{
        cout<<fixed<<setprecision(2)<<1.00;
        return 0;
    }
    cout<<fixed<<setprecision(2)<<(long double)goal;
    return 0;
}