#include<iostream>
#include<iomanip>
using namespace std;
void triangle(int line){
    int n=1;
    for(int i=1;i<=line;i++){
        int temp1=n;
        int time=0;
        n=temp1;
        int temp2=i;
         for (int j = 0; j < line - i; j++) {
            cout << "  ";
            }
        while(time<i){
            cout<<setw(2)<<setfill('0')<<n;
            n++;
            time++;
        }
        cout<<endl;
    }
    }

void square(int line){
    int n=1;
    for(int i=1;i<=line;i++){
        int temp=n;
        int time=0;
        n=temp;
        while(time<line){
            cout<<setw(2)<<setfill('0')<<n;
            n++;
            time++;
        }
        cout<<endl;
}
}
int main(){
    int line;
    cin>>line;
    square(line);
    cout<<endl;
    triangle(line);
    return 0;
}