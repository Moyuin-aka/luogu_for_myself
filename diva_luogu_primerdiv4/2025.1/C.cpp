#include<bits/stdc++.h>
using namespace std;
long long num(int x,int c,int k){
    while(k>1){
        x=(x*x+c)%10000;
        k--;
    }
    return x;
}
int main(){
    int x,c,k;
    cin>>x>>c>>k;
    int pass=num(x,c,k);
    cout<<pass<<endl;
}