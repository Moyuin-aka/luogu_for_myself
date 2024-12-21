#include<bits/stdc++.h>
using namespace std;
struct com{
    int start,end;
};
int main(){
    int n;
    cin>>n;
    vector<com>t(n);
    for(int i=0;i<n;i++){
        cin>>t[i].start>>t[i].end;
    }
    sort(t.begin(),t.end(),[](const auto a,const auto b){
        if(a.end!=b.end){
            return a.end<b.end;
        }
        else{
            return a.start<b.start;
        }
    });
    /*for(const auto n:t){
        cout<<n.start<<" "<<n.end<<endl;
    }*/
    int count=1;
    int tempstart=t[0].end;
    for(int i=1;i<n;i++){
        if(t[i].start>=tempstart){
            count++;
            tempstart=t[i].end;
        }
    }
    cout<<count<<endl;
    return 0;
}