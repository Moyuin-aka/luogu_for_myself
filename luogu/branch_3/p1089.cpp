#include<iostream>
using namespace std;
int main(){
    int n=0;
    int ans[12];
    double sum=0.0;
    for(int i=0;i<12;i++){
        cin>>ans[i];
    }
    for(int i=0;i<12;i++){
        n+=300-ans[i];
        while(n>=100){
            n-=100;
            sum+=100;
        }
        if(n<0){
            cout<<-i-1;
            return 0;
        }
    }

    cout<<(sum*1.2)+n;
    return 0;
}