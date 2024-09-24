#include<iostream>
using namespace std;
int main(){
    float m,h;
    cin>>m>>h;
    float bmi=m/(h*h);
    if(bmi<18.5){
        cout<<"Underweight"<<endl;
    }
    else if(bmi>=24){
        cout<<bmi<<endl;
        cout<<"Overweight"<<endl;
    }
    else{
        cout<<"Normal"<<endl;
    }
    return 0;
}