#include<iostream>
#include<vector>
using namespace std;
int main(){
    int tree,n;
    cin>>tree>>n;
    vector<bool>trees(tree+1,true);
    vector<bool>grass(tree,true);
    int ans[n][3];
    for(int i=0;i<n;i++){
        int type,begin,end;
        cin>>type>>begin>>end;
        ans[i][0]=type;
        ans[i][1]=begin;
        ans[i][2]=end;
    }
    for(int j=0;j<n;j++){
        if(ans[j][0]==1){
            for(int t=ans[j][1];t<ans[j][2];t++){
                grass[t-1]=false;
            }
            for(int t=ans[j][1];t<ans[j][2]-1;t++){
                trees[t+1]=false;
            }
        }
        else if(ans[j][0]==2){
            for(int t=ans[j][1];t<=ans[j][2];t++){
                trees[t]=false;
            }
           for(int t=ans[j][1];t<ans[j][2];t++){
            grass[t-1]=false;
           }
        }
    }
    int c1=0,c2=0;
    for(int i=1;i<=tree;i++){
        if(trees[i]){
            c1++;
        }
    }
    for(int i=0;i<tree-1;i++){
        if(grass[i]){
            c2++;
        }
    }
    cout<<c1<<" "<<c2;
    return 0;
}