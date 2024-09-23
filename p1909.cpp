#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[3];
    for(int i=0;i<3;i++){
        int num1,num2,num1_sum,t=1;
        cin>>num1>>num2;
        num1_sum=num1;
        while(num1_sum<n){
            num1_sum=num1_sum+num1;
            t++;
        }
        ans[i]=num2*t;
    }
    int minval=ans[0];
    for(int i=0;i<3;i++){
        if(minval>ans[i]){
            minval=ans[i];
        }
    }
    cout<<minval<<endl;
    return 0;
    
}