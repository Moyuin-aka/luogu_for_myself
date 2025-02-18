#include<bits/stdc++.h>
using namespace std;
int main(){
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    vector<int>ans;
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                ans.push_back(i+j+k);
            }
        }
    }
    sort(ans.begin(),ans.end());
    int t=0;
    int k=0;
    vector<int>max;
    for(int i=0;i<=s1*s2*s3-1;i++){
        if(ans[i+1]!=ans[i]){
            max.push_back(t);
            t=0;
            k++;
            continue;
        }
        t++;
    }
    int type=3;
    int temp=max[0];
    for(int i=0;i<k;i++){
        if(max[i]>temp){
            temp=max[i];
            type=3+i;
        }
    }
    cout<<type;
    return 0;
}