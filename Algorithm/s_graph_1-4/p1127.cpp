#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void dfs(int u,vector<vector<string>>&adj,vector<string>&res){
    while(!adj[u].empty()){
        string s=adj[u].front();
        adj[u].erase(adj[u].begin());
        dfs(s.back()-'a',adj,res);
        res.push_back(s);
    }
}

int main(){
    // 一个欧拉路径遍历的图？
    int n;
    cin>>n;
    vector<string>str(n);
    for(int i=0;i<n;i++) cin>>str[i];
    vector<vector<string>>adj(26);
    for(string &s:str){
        adj[s[0]-'a'].push_back(s); //存单词去建立映射关系
    }
    for(auto &v:adj) sort(v.begin(),v.end()); //保证字母序
    vector<int>indegree(26,0),outdegree(26,0);
    for(int i=0;i<26;i++){
        for(string &s:adj[i]){
            outdegree[i]++;
            indegree[s.back()-'a']++;
        }
    }
    // 欧拉路径必要条件：有一个起点满足 outdegree-indegree=1，有一个终点满足 indegree-outdegree=1，其余点indegree=outdegree
    int start=-1,end=-1;
    for(int i=0;i<26;i++){
        if(outdegree[i]-indegree[i]==1){
            if(start==-1) start=i;
            else { //多于一个起点
                cout<<"***"<<endl;
                return 0;
            }
        }
        else if(indegree[i]-outdegree[i]==1){
            if(end==-1) end=i;
            else { //多于一个终点
                cout<<"***"<<endl;
                return 0;
            }
        }
        else if(indegree[i]!=outdegree[i]){
            cout<<"***"<<endl;
            return 0;
        }
    }
        vector<string>res;
        if(start==-1){ //没有起点，说明是回路，从任意点开始
            for(int i=0;i<26;i++){
                if(outdegree[i]>0){
                    start=i;
                    break;
                }
            }   
        }
        dfs(start,adj,res);
        if(res.size()!=n){ //没有遍历完所有边
            cout<<"***"<<endl;
            return 0;
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<(i==res.size()-1?"":".");
        }
        return 0;
    }