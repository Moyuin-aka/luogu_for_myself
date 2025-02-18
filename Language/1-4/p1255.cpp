#include<bits/stdc++.h>
using namespace std;

// 高精度加法函数
string addHighPrecision(string num1, string num2) {
    int carry = 0;
    string result;
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int i = 0;
    while (i < num1.size() || i < num2.size() || carry != 0) {
        int d1 = (i < num1.size()) ? (num1[i] - '0') : 0;
        int d2 = (i < num2.size()) ? (num2[i] - '0') : 0;
        
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
        
        i++;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// 计算斐波那契数列的第n项
string fibonacci(int n) {
    if (n == 0 || n == 1) {
        return "1";
    } else if (n == 2) {
        return "2";
    }
    
    string f_prev_prev = "1"; // f(1)
    string f_prev = "2";     // f(2)
    
    for (int i = 3; i <= n; ++i) {
        string new_f = addHighPrecision(f_prev, f_prev_prev);
        f_prev_prev = f_prev;
        f_prev = new_f;
    }
    
    return f_prev;
}

// 主函数
int main() {
    int n;
    cin >> n;
    
    
    string result = fibonacci(n);
    cout << result << endl;
    
    return 0;
}