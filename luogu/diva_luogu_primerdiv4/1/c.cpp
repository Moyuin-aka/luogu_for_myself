#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[n][2];
    for(int i=0;i<n;i++){
        int day,gap;
        cin>>day>>gap;
        ans[i][0]=day;
        ans[i][1]=gap;
    }
    int temp=ans[0][0]+ans[0][1]*7;
    int t=ans[0][0],k=ans[0][1];
    for(int j=0;j<n;j++){
        if(ans[j][0]+ans[j][1]*7<temp){
            temp=ans[j][0]-1+ans[j][1]*7;
            t=ans[j][0];
            k=ans[j][1];
        }
    }
    int time=k*7-(6-t);
    cout<<time;
    return 0;
}