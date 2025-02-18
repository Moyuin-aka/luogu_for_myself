#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
void processClass(int studentNum, unordered_map<int, int> &participationMap, unordered_map<int, int> &scoreMap) {
    vector<int> id(studentNum);
    vector<int> rate(studentNum);
    vector<int> score(studentNum);

    for (int j = 0; j < studentNum; j++) {
        cin >> id[j];
    }
    sort(id.begin(), id.end());

    for (int j = 0; j < studentNum; j++) {
        cin >> rate[j];
        participationMap[id[j]] = rate[j];
    }
    sort(rate.begin(),rate.end());
    reverse(rate.begin(),rate.end());

    for (int j = 0; j < studentNum; j++) {
        cin >> score[j];
        scoreMap[rate[j]] = score[j];
    }
}
int main(){
    int classCount;
    cin>>classCount;
    int sum=0;
    int count=0;
    unordered_map<int, int> participationMap; // 学号对应参与度
    unordered_map<int, int> scoreMap; 
    
    for(int i=0;i<classCount;i++){
        int studentNum;
        cin>>studentNum;
        
        processClass(studentNum, participationMap, scoreMap);
    }
        int target;
        cin>>target;
        for(int i=0;i<classCount;i++){
        if(participationMap.find(target)!=participationMap.end()){
            int rateTarget=participationMap[target];
            if(scoreMap.find(rateTarget)!=scoreMap.end()){
                sum+=scoreMap[rateTarget];
                count+=1;
            }
        }
    }

    if(count==0){
        cout<<0;
        return 0;
    }
    cout<<sum/count*1.0;
   return 0;

}