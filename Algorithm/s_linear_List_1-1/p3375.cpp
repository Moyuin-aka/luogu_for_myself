#include<bits/stdc++.h>
using namespace std;

vector<int>next(string s){
    int n=s.size();
    int j=0;//前缀
    vector<int>next(n,0);
    for(int i=1;i<n;i++){//后缀
        while(j>0&&s[i]!=s[j]) j=next[j-1];
        if(s[j]==s[i]) j++;
        next[i]=j;
    }
    return next;
}
vector<int>KMP(string s,string p){
    int sz1=s.size(),sz2=p.size();
    vector<int>Next=next(p);
    vector<int>v;
    for(int i=0,j=0;i<sz1;i++){
        if(s[i]==p[j]){
            j++;
        }
        else if(j>0){
            j=Next[j-1];
            i--;
        }
        if(j==sz2){
            v.push_back(i-j+1);
            j=Next[j-1];
        }
    }
    return v;    
}

int main(){
    string s,p;
    cin>>s>>p;
    vector<int>ans=KMP(s,p);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<endl;
    }
    vector<int>Next=next(p);
    for(int i=0;i<Next.size();i++){
        cout<<Next[i]<<" ";
    }
    return 0;
}