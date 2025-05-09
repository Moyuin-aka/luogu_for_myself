#include<bits/stdc++.h>
using namespace std;
string website="https://www.luogu.com.cn/problem/";
int main(){
    int T;
    cin>>T;
    while(T--){
        string t;
        cin>>t;
        if(isdigit(t[0]))t='P'+t;
        cout<<website+t<<endl;
    }
    return 0;
}
