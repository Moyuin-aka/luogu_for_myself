#include<bits/stdc++.h>
using namespace std;
string sum;
int main(){
    string a,b;
    cin>>a>>b;
    int al=a.length(),bl=b.length();
    if(al<bl){
        for(int i=1;i<=bl-al;i++){
            a="0"+a;
        }
    }
    else{
        for(int i=1;i<=al-bl;i++){
            b="0"+b;
        }
    }
        al=a.length();
        int c=0;
        int temp;
        for(int i=al-1;i>0;i--){
            temp=a[i]-'0'+b[i]-'0';
            if(temp>=10){
            c=temp%10;
            temp%=10;
            a[i-1]++;
            }
            sum=char(temp+'0')+sum;
        }
        temp=a[0]-'0'+b[0]-'0';
        if(temp>=10){
            int c=temp%10;
            int d=temp/10;
            sum=char(c+'0')+sum;
            sum=char(d+'0')+sum;
        }
        else{
        sum=char(temp+'0')+sum;
        }
        cout<<sum;
}