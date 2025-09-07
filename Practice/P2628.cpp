#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 两种特殊符号可以改变棋子的行走。
//  一种是“*”符号，一旦棋子走完了掷骰子的步数，最终停留在这个符号上，后面又紧跟着两个以上“*”，就要受到后退惩罚，需要退后k步，
//一种是“>”符号，一旦棋子走完了掷骰子的步数，最终停留在这个符号上，后面有紧跟着2个以上“>”，那么棋子就可以获得前进奖励，可以沿着“>”一直一步步前进，直到遇到一个不是“>”的符号位置停下来。
// 每次掷数后，奖励或惩罚至多一次，如果奖励或惩罚后棋子又落在第二种特殊符号上，则不能再受到奖励或惩罚。

// 走的棋子超出棋纸右边界最后一个符号，则停在最后一个符号上；如果超出左边界，则停在第一个符号上。

int main(){
    string s;
    getline(cin,s);
    int n;
    cin>>n;
    vector<int>turn(n);
    for(int i=0;i<n;i++){
        cin>>turn[i];
    }

    long long pos=-1; // 当前位置,从0开始,计数是1到s.size()-1
    for(long long i=0;i<n;i++){
        pos+=turn[i];
        if(pos>=s.size()-1) pos=s.size()-1-1; 
        if(pos<0) pos=0;  
        if(s[pos]=='*' && pos+2<s.size()-1 && s[pos+1]=='*' && s[pos+2]=='*'){
            //这里比较难的是记录退后多少步，要记录当前位置到连续最后一个*的数量。
            long long cnt=0;
            while(pos+cnt<s.size()-1 && s[pos+cnt]=='*'){
                cnt++;
            }
            pos-=cnt;
            if(pos<0) pos=0;
        }
        else if(s[pos]=='>' && pos+2<s.size()-1 && s[pos+1]=='>' && s[pos+2]=='>'){
            while(pos+1<s.size()-1 && s[pos]=='>'){
                pos++;
            }
            if(pos>=s.size()-1) pos=s.size()-1-1;
            
        }
        //cout<<pos+1<<endl;
    }
    cout<<pos+1<<" "<<s.size()-1-1-pos<<endl;
    return 0;
}