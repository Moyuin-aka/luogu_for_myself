#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>fi(n);
    for(int i=0;i<n;i++){
        cin>>fi[i];
    }
    for(int i=0;i<n;i++){
        string &row=fi[i];
        int wall=row.find('H');
        if(wall!=string::npos){
            
            int a=0,b=0;
            for(int j=0;j<wall;j++){
                if(row[j]=='A') a++;
            }
            for(int j=wall+1;j<m;j++){
                if(row[j]=='B') b++;
            }
            row=string(a,'A')+string(wall-a,'#')+'H'+string(m-wall-1-b,'#')+string(b,'B');
        }
        else{
            int a=0,b=0;
            for(char c:row){
                if(c=='A') a++;
                if(c=='B') b++;
            }
            if(a>b){
                row=string(m-a,'#')+string(a,'A');
            }
            else if(b>a){
                row=string(b,'B')+string(m-b,'#');
            }
            else{
                row=string(m,'#');
            }
        }
    }
    vector<string>re=fi;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(fi[i][j]=='A'||fi[i][j]=='B'){
                bool has=false;
                if(i>0&&fi[i-1][j]==fi[i][j]) has=true;
                if(i<n-1&&fi[i+1][j]==fi[i][j])has=true;
                //if(j>0&&fi[i][j-1]==re[i][j])has=true;
                //if(j<m-1&&fi[i][j+1]==re[i][j])has=true;
                if(has){
                    re[i][j]='#';
                }
            }
        }
    }
    for (const string& row : re) {
        cout << row << endl;
    }
    return 0;
}