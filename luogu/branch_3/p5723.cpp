#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int L,times=0,sum=0,i=2;
    cin>>L;
    while(sum<L){
        if(isPrime(i)){
            sum+=i;
            if(sum>L){
                sum-=i;
                break;
            }
            cout<<i<<endl;
            times+=1;
        }
        i++;
    }
    cout<<times<<endl;
    return 0;

}