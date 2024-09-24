#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   int values[3];
   cin>>values[0]>>values[1]>>values[2];
   string order;
   cin>>order;
   int maxvalue=*max_element(values,values+3);
   int minvalue=*min_element(values,values+3);
   int midvalue=values[0]+values[1]+values[2]-maxvalue-minvalue;
   for(char ch:order){
    if(ch=='C'){
        cout<<maxvalue<<" ";
    }else if(ch=='B'){
        cout<<midvalue<<" ";
    }else if(ch=='A'){
        cout<<minvalue<<" ";
    }
   }
   cout<<endl;
   return 0;

}