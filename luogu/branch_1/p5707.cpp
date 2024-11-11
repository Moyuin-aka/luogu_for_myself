#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double s,v;
    cin>>s>>v;
    int t=ceil(s/v)+10;
    int hour=7-(t/60);
    int min=60-(t%60);
    if(hour<0){
        hour+=24;
    }
    cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<endl;
    return 0;
}
