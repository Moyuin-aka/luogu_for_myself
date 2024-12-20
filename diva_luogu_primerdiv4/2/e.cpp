#include<bits/stdc++.h>
using namespace std;
int main(){
    int coin,card;
    cin>>coin>>card;
    int arr[5]={0};
    for(int t=1;t<=card;t++){
        int cardarr[5];
        int minn=9;
        for(int i=0;i<5;i++){
            cin>>cardarr[i];
            minn=min(cardarr[i],minn);
        }
        
        if(coin>=minn){
            int maxnum=-1;
            for(int i=0;i<5;i++){
                if(coin>=cardarr[i]&&cardarr[i]>maxnum){
                    maxnum=cardarr[i];
                }
            }
            //cout<<maxnum<<endl;
            arr[maxnum-1]++;
            coin-=maxnum;

        }
    }
    for(int n=0;n<5;n++){
        cout<<arr[n]<<" ";
    }
    cout<<endl<<coin;
}
