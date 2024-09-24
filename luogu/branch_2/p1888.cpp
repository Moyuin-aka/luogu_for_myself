#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){
    while(b!=0){
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(){
  long long a,b,c;
    cin>>a>>b>>c;
    long long minval=min({a,b,c});
    long long maxval=max({a,b,c});
    long long gcdvalue=gcd(minval,maxval);
    minval/=gcdvalue;
    maxval/=gcdvalue;
    cout<<minval<<"/"<<maxval<<endl;
    return 0;
}  