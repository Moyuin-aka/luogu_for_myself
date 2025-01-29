#include<bits/stdc++.h>
using namespace std;

struct Milk{
    double price;
    double count;
};

int main(){
    double n,m;
    cin>>n>>m;
    vector<Milk>milk(m);
    for(int i=0;i<m;i++){
        cin>>milk[i].price>>milk[i].count;
    }
    sort(milk.begin(),milk.end(),[](const Milk &a,const Milk &b){
        if(a.price==b.price) return a.count>b.count;
        return a.price<b.price;
    });
    double temp=0;
    int p=0;
    for(int i=0;i<m;i++){
        //cout<<milk[i].price<<" "<<milk[i].count<<endl;
        if(temp==n) break;
        if(temp+milk[i].count>n){
            p+=(n-temp)*milk[i].price;
            temp=n;   
            continue;
        }
        temp+=milk[i].count;
        p+=milk[i].price*milk[i].count;
    }
    cout<<p<<endl;
    return 0;
}