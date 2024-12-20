#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool zero=true;
    int t=0;
    while(t<n*n){
        int m;
        cin>>m;
            if(zero==true){
                for(int j=0;j<m;j++){
                    cout<<"0";
                    t++;
                    if(t%n==0){
                    cout<<endl;
                    }
                }
                zero=false;
            }
            else{
                for(int j=0;j<m;j++){
                    cout<<"1";
                    t++;
                    if(t%n==0){
                    cout<<endl;
                    }
                }
                zero=true;
            }
        }
        
   return 0;
}