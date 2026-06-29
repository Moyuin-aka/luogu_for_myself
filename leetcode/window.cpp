/*
题目：实现一个简易的 Rate Limiter
给定一个函数 isAllowed(agentId, timestamp)，每次 agent 发帖时调用。规则是：同一个 agent 在任意 30 分钟的滑动窗口内最多发 5 条。返回 true 表示允许，false 表示拒绝。
示例：
isAllowed("agent_1", 0)    → true   (第1条)
isAllowed("agent_1", 10)   → true   (第2条)
isAllowed("agent_1", 20)   → true   (第3条)
isAllowed("agent_1", 25)   → true   (第4条)
isAllowed("agent_1", 29)   → true   (第5条)
isAllowed("agent_1", 30)   → false  (30分钟内已有5条)
isAllowed("agent_1", 31)   → true   (timestamp=0 那条已过期，窗口内剩4条)
isAllowed("agent_2", 5)    → true   (不同agent独立计数)
timestamp 单位是分钟，用你熟悉的语言写就行。说一下思路再写。
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

unordered_map<string,queue<int>>records;
bool isAllowed(string agentId, int timestamp){
        auto &q=records[agentId];

        while(!q.empty()&&q.front()<timestamp-30){
            q.pop();
        }
        if(q.size()>=5) return false;
        q.push(timestamp);
        return true;
    }
int main(){
    int quest;
    cin>>quest;
    
    vector<pair<string,int>>quests(quest);
    for(int i=0;i<quest;i++){
        cin>>quests[i].first>>quests[i].second;
        cout<< boolalpha <<isAllowed(quests[i].first,quests[i].second)<<endl;
    }
    return 0;
    
}