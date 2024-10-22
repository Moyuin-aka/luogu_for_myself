#include<iostream>
using namespace std;
int main(){
    double miles;
    cin>>miles;
    int foots=0;
    double sum=0,i=2;
    while(sum<miles){
        sum+=i;
        i*=0.98;
        foots+=1;
    }
    cout<<foots;
    return 0;
}