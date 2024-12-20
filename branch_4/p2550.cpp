#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[n][7];
    int judge[7];
    for(int i=0;i<7;i++){
        cin>>judge[i];
    }
    int t[7]={0};
    for(int k=0;k<n;k++){
        for(int i=0;i<7;i++){
            cin>>ans[k][i];
        }
    }    
    for(int k=0;k<n;k++){
        int count=0;
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if(ans[k][i]==judge[j]){
                    count++;
                }
            }
        }
        switch(count){
            case(7):
                t[0]++;
                break;
            case(6):
                t[1]++;
                break;
            case(5):
                t[2]++;
                break;
            case(4):
                t[3]++;
                break;
            case(3):
                t[4]++;
                break;
            case(2):
                t[5]++;
                break;
            case(1):
                t[6]++;
                break;
            default:
                break;
        }
    }
    for(int n:t){
        cout<<n<<" ";
    }
    return 0;
}