#include<iostream>
using namespace std;
int main(){
    int n,cup;
    float t,ml;
    cin>>t>>n;
    cup=n*2;
    ml=t/n;
    printf("%.3f\n",ml);
    printf("%d",cup);
    return 0;
}