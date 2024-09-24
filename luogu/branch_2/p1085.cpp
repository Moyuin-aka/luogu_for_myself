#include<iostream>
using namespace std;
int main(){
      int arr[7];
      for(int i=0;i<7;i++){
        int num1,num2;
        cin>>num1>>num2;
        arr[i]=num1+num2;
      }
      int maxval=arr[0],day;
      for(int i=1;i<7;i++){
        if(arr[i]>maxval){
            maxval=arr[i];
            day=i+1;
        }
        }
        
        cout<<day<<endl;
      
      return 0;
      

}