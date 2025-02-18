#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q = 0;
    cin >> q;
    cin.ignore(); // 清除缓冲区中的换行符，防止影响后续的 getline

    int a = 0, b = 0;
    string str, deal;
    cin>>str;// 读取完整的一行作为初始 str

    for (int i = 0; i < q; i++)
    {
        int A;
        cin >> A;
        cin.ignore(); // 每次 cin >> A 之后清除换行符

        switch (A)
        {
        case 1:
            cin>>deal; // 读取一行并添加到 str 末尾
            str.append(deal);
            cout << str << endl;
            break;
        case 2:
            cin >> a >> b;
            cin.ignore(); // 这里忽略换行符
            cout << str.substr(a, b) << endl;
            str = str.substr(a, b); // 更新 str
            break;
        case 3:
            cin >> a;
            cin.ignore(); // 清除换行符
            cin>>deal; // 在指定位置插入字符串
            cout << str.insert(a, deal) << endl;
            break;
        case 4:
            cin>>deal; // 查找字符串的位置
            size_t found = str.find(deal, 0);
            if (found != string::npos)
            {
                cout << found << endl;
            }
            else
                cout << "-1" << endl;
            break;
        }
    }
}
