#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string numbers;
    cin >> numbers;

    // 定义每个数字的3x5点阵表示
    string digitPatterns[10][5] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
    };
    vector<string> result(5, "");
    for (int i = 0; i < n; i++) {
        int digit = numbers[i] - '0';
        if (i > 0) {
            for (int j = 0; j < 5; j++) {
                result[j] += "."; // 间隔为一个点
            }
        }
        for (int j = 0; j < 5; j++) {
            result[j] += digitPatterns[digit][j];
        }
    }
    for (const string& line : result) {
        cout << line << endl;
    }

    return 0;
}
