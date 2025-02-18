#include<iostream>
using namespace std;
/*
int main(){
    int sum=0;
    int n;
    cin>>n;
    int x=100;
    int k=1;
    bool found = false;
    while(!found && x > 0){
        for(k=1;k<=100;k++){
            int sum=0;
            for(int i=0;i<7;i++){
            sum+=x+i*k;
            }
             sum*=52;
        if(sum==n){
            found=true;
            break;
        }
    }
    if(!found){
        x--;
    }
}
    cout<<x<<endl<<k;
    return 0;
   */ 
int main() {
    int n;
    cin >> n;
    int x = 100;  // 从最大可能的X开始
    int k = 1;

    // 遍历X的所有可能值
    while (x > 0) {
        for (k = 1; k <= 100; k++) {
            int sum = 0;
            // 计算每周的金额
            for (int i = 0; i < 7; i++) {
                sum += x + i * k;
            }
            sum *= 52;  // 总共52周

            // 检查是否匹配目标金额
            if (sum == n) {
                cout << x << endl << k << endl;
                return 0;  // 立即退出程序
            }
        }
        x--;  // 如果当前x和k不满足条件，减少x
    }

    return 0;
}

