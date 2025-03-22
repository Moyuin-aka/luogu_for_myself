#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    queue<pair<int, vector<int>>> timeWindow; // 队列存储<时间, 国籍列表>
    unordered_map<int, int> nationCount; // 统计每个国籍在时间窗口内的出现次数
    
    for (int i = 0; i < n; i++) {
        int t, k;
        cin >> t >> k;
        
        vector<int> nations(k);
        for (int j = 0; j < k; j++) {
            cin >> nations[j];
            nationCount[nations[j]]++; // 增加国籍计数
        }
        
        timeWindow.push({t, nations}); // 将当前船加入队列
        
        // 移除超过时间窗口的船只
        while (!timeWindow.empty() && timeWindow.front().first <= t - 86400) {
            auto [old_t, old_nations] = timeWindow.front();
            timeWindow.pop();
            
            for (int nation : old_nations) {
                nationCount[nation]--; // 减少国籍计数
                if (nationCount[nation] == 0) {
                    nationCount.erase(nation); // 如果计数为0，从统计中删除
                }
            }
        }
        
        cout << nationCount.size() << endl; // 输出当前不同国籍的数量
    }
    
    return 0;
}