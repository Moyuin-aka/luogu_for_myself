#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    cout<<'/';
    for(int i=0;i<s.length();i++){
        if(s[i]<='Z'&&s[i]>='A'){
            cout<<char(s[i]-('A'-'a') 
        }
        if(s[i]==']'){
            count++;
        }
        if(count==2){
            break;
        }
    }
    return 0;
}