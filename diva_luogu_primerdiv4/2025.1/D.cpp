#include<bits/stdc++.h>
using namespace std;
struct person{
    int id;
    int time;
};
int main(){
    int num;
    cin>>num;
    vector<person>line(num);
    for(int i=0;i<num;i++){
        cin>>line[i].time;
        line[i].id=i+1;
    }
    sort(line.begin(),line.end(),[](const person&a,const person&b){
        if(a.time<=15||b.time<=15){
            if(b.time<=15&&a.time<=15) return a.id<b.id;
            return a.time<b.time;
        }
        return a.id<b.id;
    });
    for(auto &i:line){
        cout<<i.time<<" ";
    }
    cout<<endl;
}