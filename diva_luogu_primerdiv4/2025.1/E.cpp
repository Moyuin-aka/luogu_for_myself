#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>>tri(n,vector<char>(m,'.'));
    for(int i=0;i<k;i++){
        int l=(m-(m-2*i+1)/2);
        int r=l+2*i;
        for(int j=l;j<=r;j++){
            tri[i][j]='#';
        }
    }
    for(int i=k;i<n-k;i++){
        for(int j=0;j<m;j++){
            tri[i][j]='#';
        }
    }
     for(int i=n-k;i<n;i++){
        int l=(m-(2*(m-i-1)+1))/2;
        int r=l+2*(n-i-1);
        for(int j=l;j<=r;j++){
            tri[i][j]='#';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<tri[i][j];
        }
        cout<<endl;
    }
}