#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,x;//开始，频率，开始，频率,时间
    cin>>a>>b>>c>>d>>x;
    cout<<(x>=a?b:0)+(x>=c?d:0)<<endl;
    return 0;
}