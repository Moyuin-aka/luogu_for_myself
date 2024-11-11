#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<"1"<<endl;
    for(int i=1;i<n;i++){
        int temp=1;
        cout<<temp<<" ";
        for(int j=0;j<i;j++){
            temp=temp*(i-j)/(j+1);
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}