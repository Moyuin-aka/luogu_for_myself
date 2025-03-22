#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    // 记录每个位置的括号是否已匹配
    vector<bool> matched(n, false);
    stack<int> left_brackets;
    
    // 第一遍扫描，标记所有能配对的括号
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            left_brackets.push(i);
        } else { // 右括号
            if (!left_brackets.empty()) {
                int left_idx = left_brackets.top();
                // 检查是否匹配
                if ((s[i] == ')' && s[left_idx] == '(') || -
                    (s[i] == ']' && s[left_idx] == '[')) {
                    matched[i] = true;
                    matched[left_idx] = true;
                    left_brackets.pop();
                }
            }
        }
    }
    
    // 构建结果字符串
    string result = "";
    for (int i = 0; i < n; i++) {
        if (matched[i]) {
            result += s[i]; // 已匹配的括号直接添加
        } else {
            if (s[i] == '(') {
                result += "()"; // 未匹配的左小括号添加右小括号
            } else if (s[i] == '[') {
                result += "[]"; // 未匹配的左中括号添加右中括号
            } else if (s[i] == ')') {
                result += "()"; // 未匹配的右小括号添加左小括号
            } else { // s[i] == ']'
                result += "[]"; // 未匹配的右中括号添加左中括号
            }
        }
    }
    
    cout << result << endl;
    return 0;
}