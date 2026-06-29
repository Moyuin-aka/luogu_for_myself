/*示例：
输入: "10"
输出: "1010"

输入: "255"
输出: "11111111"

输入: "999999999999999999999999999999"
输出: (一个很长的二进制串)
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string num;
    cin >> num;
    if (num == "0")
    {
        cout << "0" << endl;
        return 0;
    }
    string res = "";
    while (num != "0")
    {
        string next = "";
        int carry = 0; // 余数
        for (char c : num)
        {
            int cur = carry * 10 + (c - '0');
            next += char(cur / 2 + '0');
            carry = cur % 2;
        }
        int start = 0;
        while (start < next.size() - 1 && next[start] == '0')
            start++;              // 去掉前面多余的 000
        num = next.substr(start); // 避免出现next="02"的情况

        res += char(carry + '0');
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
