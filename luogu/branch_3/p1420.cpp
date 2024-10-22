#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ans[n];
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int numAll=1;//连号至少有一个数字
    int length=1;//连号至少有以一个长度
    for(int j=0;j<n;j++){
        if(ans[j+1]-ans[j]==1){
            length++;
        }
        else{
            numAll=max(numAll,length);
            length=1;//要找最长连号，可能会有多种情况，所以要让length重置后最后判断最长length最终回到数字中
        }
    }
    cout<<numAll;
    return 0;
}
