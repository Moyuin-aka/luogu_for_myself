#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int>num;
    string snum="";
    for(int i=0;i<s.find('@');i++){
        if(s[i]=='.'){
            int number=stoi(snum);
            num.push_back(number);
            snum="";
            continue;
        }
        if(s[i]=='+'){
            int index=num.size();
            num[index-2]=num[index-2]+num[index-1];
            num.pop_back();
        }
        else if(s[i]=='-'){
            int index=num.size();
            num[index-2]=num[index-2]-num[index-1];
            num.pop_back();
        }
        else if(s[i]=='*'){
            int index=num.size();
            num[index-2]=num[index-2]*num[index-1];
            num.pop_back();
        }
        else if(s[i]=='/'){
            int index=num.size();
            num[index-2]=num[index-2]/num[index-1];
            num.pop_back();
        }
        else{
            snum+=s[i];
        }
        //if(!num.empty())
        //cout<<num[num.size()-1]<<endl;
    }
    cout<<num[0]<<endl;
}