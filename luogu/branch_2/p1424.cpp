#include<iostream>
using namespace std;
int calculate_workdays(int x,int n){
    int weeks=n/7;
    int workdays=weeks*5;
    int remaining_days=n%7;
    for(int i=0;i<remaining_days;i++){
        if((x+i-1)%7+1<=5){
            workdays++;
        }
    }
    return workdays;
}
int main(){
    int n,x;
    cin>>x>>n;
    int result=calculate_workdays(x,n);
    int m=result*250;
    cout<<m;
    return 0;
}