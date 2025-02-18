#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,day;
    cin>>num>>day;
    vector<int>height(num);
    while(day--){
        string s;
        cin>>s;
        if(s=="water"){
            int begin,end;
            cin>>begin>>end;
            for(int i=begin-1;i<=end-1;i++){
                height[i]++;
            }
        }
        else if(s=="rise"){
            int begin,end,goal;
            int count=0;
            cin>>begin>>end>>goal;
            for(int i=begin-1;i<=end-1;i++){
                if(height[i]>=goal){
                    height[i]=0;
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}