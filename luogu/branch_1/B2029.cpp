#include<iostream>
using namespace std;
int main(){
    const float pi=3.14;
    int h,r,n=0;
    cin>>h>>r;
    double sum,v=pi*r*r*h;
    while(sum<=20000){
        sum+=v;
        n++;
    }
    cout<<n<<endl;
    return 0;
}
