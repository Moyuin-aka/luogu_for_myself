#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const unordered_map<string,int>order={
    {"push",1},
    {"pop",2},
    {"query",3},
    {"size",4}
};
void receive(string s,stack<ll>&st){
    int num=order.at(s);
    if(num==1){
        ll x;
        cin>>x;
        st.push(x);
    }
    else if(num==2){
        if(st.empty()) cout<<"Empty"<<endl;
        else st.pop();
    }
    else if(num==3){
        if(st.empty()) cout<<"Anguei!"<<endl;
        else cout<<st.top()<<endl;
    }
    else if(num==4){
        cout<<st.size()<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        stack<ll>st;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            receive(s,st);
        }
    }
    return 0;
}