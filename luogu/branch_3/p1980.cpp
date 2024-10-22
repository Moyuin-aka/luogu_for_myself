#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int totalcount=0;
    for(int i=1;i<=n;i++){
        int temp=i;
        int count=0;
        while(temp>0){
            if(temp%10==x){
                count++;
            }
            temp/=10;
        }
        totalcount+=count;
    }
    cout<<totalcount<<endl;
    return 0;
}
