#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    double num1=0,num2=0,t1=0,t2=0;
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=i+1;
        if(ans[i]%k==0){
         c  t1++;
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