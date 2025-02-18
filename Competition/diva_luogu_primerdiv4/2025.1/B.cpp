#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>line(100);
    for(int i=0;i<100;i++){
        if(i<50){
            line[i]=(49-i)*2+1;
        }
        else{
            line[i]=(i-50)*2;
        }
    }
    int a,b;
    cin>>a>>b;
    int indexa,indexb;
    for(int i=0;i<100;i++){
        if(line[i]==a) indexa=i;
        if(line[i]==b) indexb=i;
    }
    //cout<<indexa<<" "<<indexb<<endl;
    cout<<abs(indexa-indexb)-1<<endl;
    return 0;
}