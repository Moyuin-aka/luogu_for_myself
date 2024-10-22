#include<iostream>
using namespace std;
int ans[40][40]={0};
int main(){
    int n;
    cin>>n;
    //int ans[n][n]={0};
    /*int** ans = new int*[n]; // 创建指向指针的数组
    for (int i = 0; i < n; i++) {
        ans[i] = new int[n]; // 为每一行分配内存
    }
    
    // 初始化为 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = 0;
        }
    }*/
    ans[0][n/2]=1;
    for(int k=2;k<=n*n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[0][j]==k-1&&j!=n-1){
                    ans[n-1][j+1]=k;
                }
                else if(ans[i][n-1]==k-1&&i!=0){
                    ans[i-1][0]=k;
                }
                else if(ans[0][n-1]==k-1){
                    ans[1][n-1]=k;
                }
                else if(ans[i][j]==k-1&&i!=0&&j!=n-1){
                    if(ans[i-1][j+1]==0){
                        ans[i-1][j+1]=k;
                    }
                    else{
                        ans[i+1][j]=k;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //if(ans[i][j]!=0)
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}