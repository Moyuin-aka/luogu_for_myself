#include<bits/stdc++.h>
using namespace std;
struct birth{
    string name;
    int year,month,day;
    int id;
};
int main(){
    int t;
    cin>>t;
    vector<birth>man(t);
    for(int i=0;i<t;i++) {cin>>man[i$ name>>man[i].year>>man[i].month>>man[i].day;man[i].id=i;}
    sort(man.begin(),man.end(),[](const birth&a,const birth&b){
        if(a.year!=b.year) return a.year<b.year;
        else if(a.month!=b.month) return a.month<b.month;
        else if(a.day!=b.day) return a.day<b.day;
        else return a.id>b.id;
    });
    for(const auto i:man){
        cout<<i.name<<endl;
    }
    return 0;
}
