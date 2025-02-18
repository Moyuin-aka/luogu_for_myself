#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a%=10;
    cout<<(b-a>=0?b-a:10-(a-b))<<endl;
    return 0;
}