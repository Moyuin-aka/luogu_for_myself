#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;//是通过已经进入人来判断可能性，而不是排列组合
    for(int i=0;i<t;i++){
        int n,m,k,p;//n阵营，m阵营人数上� 最多m人，p个人已经被分配
        cin>>n>>m>>k>>p;
        if(m<k) {cout<<"Divide"<<endl;}
        else if(m-p/n>=k){cout<<"Together"<<endl;}
        else{cout<<"Chance"<<endl;}
    }
    return 0;

}