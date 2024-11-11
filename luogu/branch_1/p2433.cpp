#include<iostream>
#include<iomanip>
#include<cmath>
// 填上你觉得需要的其他头文件
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        int apple=14,student=4;
        int a=apple/student,b=a*student,c=14-b;
        cout<<a<<' '<<b<<' '<<c<<endl;
        // 请自行完成问题 3 的代码
    } else if (T == 4) {
        double ml=500.0,student_4=3.0;
        double average_ml=ml/student_4;
        printf("%6.3f",average_ml);
        // 请自行完成问题 4 的代码
    } else if (T == 5) {
        int long_a=260,long_b=220;
        int v_a=12,v_b=20;
        int t=(long_a+long_b)/(v_a+v_b);
        cout<<t<<endl;
        // 请自行完成问题 5 的代码
    } else if (T == 6) {
        cout<<sqrt(36+81)<<endl;
        // 请自行完成问题 6 的代码
    } else if (T == 7) {
        cout<<"110\n"<<"90\n"<<"0"<<endl;
        // 请自行完成问题 7 的代码
    } else if (T == 8) {
        const float pi=3.141593;
        long double r=5;
        long double c=2*pi*r,s=pi*r*r,v=3*(pi*r*r*r)/4;
        cout<<fixed<<setprecision(19)<<c<<endl;
        cout<<fixed<<setprecision(20)<<s<<endl;
        cout<<fixed<<setprecision(22)<<v<<endl;

        // 请自行完成问题 8 的代码
    } else if (T == 9) {
        // 请自行完成问题 9 的代码
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
    } else if (T == 11) {
        // 请自行完成问题 11 的代码
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
    }
    //不想写了好长噶
    system("pause");
    return 0;
}
