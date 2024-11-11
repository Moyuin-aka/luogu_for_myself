#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x>1){
        cout<<"Today,I ate "<<x<<" apples."<<endl;
    }
    else if(x<1){
        cout<<"Today,I ate "<<x<<" apple."<<endl;
    }
    return 0;
}
