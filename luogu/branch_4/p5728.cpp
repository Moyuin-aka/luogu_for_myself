#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[n][3];
    for(int i=0;i<n;i++){
        int ch,mt,en;
        cin>>ch>>mt>>en;
        ans[i][0]=ch;
        ans[i][1]=mt;
        ans[i][2]=en;
    }
    int count=0;
    for(int i=0;i<n;i++){
        /*if(ans[i][0]-ans[i+1][0]>5||ans[i][0]-ans[i+1][0]<-5){
            continue;
        }
        if(ans[i][1]-ans[i+1][1]>5||ans[i][1]-ans[i+1][1]<-5){
            continue;
        }
        if(ans[i][2]-ans[i+1][2]>5||ans[i][2]-ans[i+1][2]<-5){
            continue;
        }
        int lower=ans[i][0]+ans[i][1]+ans[i][2]-ans[i+1][0]-ans[i+1][1]-ans[i+1][2];
        if(lower>10||lower<-10){
            continue;
        }*/
       for(int j=i+1;j<n;j++){
        if(ans[i][0]-ans[j][0]>5||ans[i][0]-ans[j][0]<-5){
            continue;
        }
        if(ans[i][1]-ans[j][1]>5||ans[i][1]-ans[j][1]<-5){
            continue;
        }
        if(ans[i][2]-ans[j][2]>5||ans[i][2]-ans[j][2]<-5){
            continue;
        }
        int lower=ans[i][0]+ans[i][1]+ans[i][2]-ans[j][0]-ans[j][1]-ans[j][2];
        if(lower>10||lower<-10){
            continue;
        }
        count++;
       }
        
    }
    printf("%d\n",count);
    return 0;
}