#include<bits/stdc++.h>
using namespace std;
struct type{
    int id;
    int time;
    double waitingtime=0;
};
int main(){
    int n;
    cin>>n;
    vector<type>line(n);
    for(int i=0;i<n;i++){
        line[i].id=i+1;
        cin>>line[i].time;
    }
    sort(line.begin(),line.end(),[](const auto &a,const auto &b){
        return a.time<b.time;
    });
    for(const auto &man:line){
        cout<<man.id<<" ";
    }
    cout<<endl;
    double sumwaiting=0;
    //等待时间是它之前的时间
    for(int i=1;i<n;i++){
        line[i].waitingtime=line[i-1].time+line[i-1].waitingtime;
        sumwaiting+=line[i].waitingtime;
    }
    sumwaiting/=n;
    cout<<fixed<<setprecision(2)<<sumwaiting<<endl;
    return 0;


}