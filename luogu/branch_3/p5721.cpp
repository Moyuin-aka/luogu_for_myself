#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<setw(2)<<setfill('0')<<count++;
        }
        cout<<endl;
    }
    return 0;
}