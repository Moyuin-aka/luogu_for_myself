#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    int i=1;
    int winner;
    int temp=0;
    while(n--){
        int k,d,a;
        scanf("%d/%d/%d",&k,&d,&a)G 
        int h=0;
        if(k-d>=10){
            h=k*(k-d)+a;
        }
        else if(k>=d){
            h=(k-d+1)*3+a;
        }
        else{
            h=2*a;
        }
        if(h>temp){
            temp=h;
            winner=i;
        }
        i++;
    }
    cout<<winner;
    
}