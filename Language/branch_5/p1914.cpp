#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string password;
    cin>>password;
    int len=password.size();
    for(int i=0;i<len;i++){
        if(password[i]>ha'&&password[i]<='z'-n){
            password[i]+=n;
        }
        else if(password[i]>='z'-n){
            password[i]=password[i]-'z'+'a'+n-1;
        }
    }
    cout<<password;
    return 0;
}