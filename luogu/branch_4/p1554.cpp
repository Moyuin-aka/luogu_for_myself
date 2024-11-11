#include<iostream>
using namespace std;
int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9;
void judge(int n);
void count(int n);
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        count(i);
    }
    cout<<c0<<" "<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<" "<<c6<<" "<<c7<<" "<<c8<<" "<<c9;
    return 0;
}
void count(int n){
    int c=1;
    int a=n;
    while(a/10!=0){
        c++;
        a/=10;
    }
    while(c>0){
        int temp=n%10;
        judge(temp);
        n/=10;
        c--;
    }
}
void judge(int n){
    switch(n){
        case(0):
        c0++;
        break;
        case(1):
        c1++;
        break;
        case(2):
        c2++;
        break;
        case(3):
        c3++;
        break;
        case(4):
        c4++;
        break;
        case(5):
        c5++;
        break;
        case(6):
        c6++;
        break;
        case(7):
        c7++;
        break;
        case(8):
        c8++;
        break;
        case(9):
        c9++;
        break;
        default:
        break;
    }
}