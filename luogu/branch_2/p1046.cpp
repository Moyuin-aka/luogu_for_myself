#include<iostream>
using namespace std;
int main(){
    int ans[10];
    for(int i=0;i<10;i++){
        int n;
        cin>>n;
        ans[i]=n;
    }
    int height;
    cin>>height;
    height+=30;
    int time=0;
    for(int i=0;i<10;i++){
        if(ans[i]<=height){
            time+=1;
    }
    } 
    cout<<time<<endl;
    return 0;
}