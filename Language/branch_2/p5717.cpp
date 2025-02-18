#include<iostream>
#include<algorithm>
using namespace std;
int middle(int a,int b,int c){
    return a+b+c-max({a,b,c})-min({a,b,c});
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int max_double,min_double,middle_double;
    max_double=max({a,b,c})*max({a,b,c});
    middle_double=middle(a,b,c)*middle(a,b,c);
    min_double=min({a,b,c})*min({a,b,c});
    if(max({a,b,c})-middle(a,b,c)<min({a,b,c})){
        if(min_double+middle_double>max_double){
            cout<<"Acute triangle"<<endl;
        }
        else if(min_double+middle_double==max_double){
            cout<<"Right triangle"<<endl;
        }
        else{
            cout<<"Obtuse triangle"<<endl;
        }
    if(min({a,b,c})==middle(a,b,c)){
        cout<<"Isosceles triangle"<<endl;
        if(max({a,b,c})==min({a,b,c})){
           cout<<"Equilateral triangle"<<endl;
        }
    }
    }
    else{
        cout<<"Not triangle"<<endl;
    }
    return 0;
}


    

