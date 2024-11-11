#include<iostream>
using namespace std;
int ans[2000000];
void change(double a,double b){
    double n=1;
    for(int i=a;n<=b;i=n*a){
        if(ans[i-1]==0){
            ans[i-1]=1;
        }
        else if(ans[i-1]==1){
            ans[i-1]=0;
        }
        n++;
    }
}
int main(){
    
    int n;
    cin>>n;
    double a,b;
    for(int j=0;j<n;j++){
        cin>>a>>b;
        change(a,b);
    }
    for(int i=0;i<2000000;i++){
        if(ans[i]==1){
            cout<<i+1;
            break;
        }
    }
    return 0;
}