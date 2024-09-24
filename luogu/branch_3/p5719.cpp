#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    double num1,num2,t1,t2;
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=i+1;
        if(ans[i]%k==0){
            t1++;
            num1+=ans[i];
        }
        else{
            t2++;
            num2+=ans[i];
        }
    }
    double ave1=num1/t1,ave2=num2/t2;
    printf("%.1f %.1f",ave1,ave2);
    return 0;   
}