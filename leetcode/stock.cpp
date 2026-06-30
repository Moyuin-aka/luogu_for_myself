/*
 * LC 121. 买卖股票的最佳时机
 *
 * 给定一个数组 prices，prices[i] 表示某支股票第 i 天的价格。
 * 你只准完成一笔交易（一次买入 + 一次卖出），返回能获得的最大利润。
 * 如果无法获利，返回 0。
 *
 * 示例：
 *   prices = [7, 1, 5, 3, 6, 4]  → 输出 5
 *   （第2天买入 1，第5天卖出 6，利润 5）
 *
 *   prices = [7, 6, 4, 3, 1]     → 输出 0
 *   （每天都跌，无法获利）
 *
 * 要求：O(n) 时间，O(1) 空间
 * 提示：遍历时只做两件事——更新最低价，更新最大利润。
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min=INT_MAX;
    int price=0;
    for(int i=0;i<prices.size()-1;i++){
        if(prices[i]<min) min=prices[i];
        int max=prices[i+1];
        if(max-min>price) price=max-min;
    }
    // TODO
    return price;
}

int main() {
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(p1) << endl; // 期望: 5

    vector<int> p2 = {7, 6, 4, 3, 1};
    cout << maxProfit(p2) << endl; // 期望: 0
    return 0;
}
