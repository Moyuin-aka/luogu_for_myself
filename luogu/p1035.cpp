#include<iostream>
using namespace std;
int main()
{
    int n=0;
    double k,sum=0.0;
    cin>>k;
    while(sum<=k){
        n++;
        sum +=1.0/n;
    }
    cout<<n;
    return 0;


}