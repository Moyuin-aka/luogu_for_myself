#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long box,x;
    cin>>box>>x;
    vector<int>boxs;
    for(long long i=0;i<box;i++){
        long long candy;
        cin>>candy;
        boxs.push_back(candy);
    }
    long long eaten=0;
    if(box==1){
    	eaten=boxs[0]-x;
    	if(eaten<0)eaten=0;
    	cout<<eaten<<endl;
    	return 0;
    }
    //最多的糖的盒子先吃掉
    for(long long i=0;i<box-1;i++){
        long long temp=boxs[i+1]+boxs[i]-x;
        if(temp<0) temp=0;
        eaten+=temp;
        //if(boxs[i+1]>=boxs[i]){
        boxs[i+1]-=temp;
        if(boxs[i+1]<=0) boxs[i+1]=0;
        //}
        /*else{
        	boxs[i]-=temp;
        }*/
        
    }
    cout<<eaten<<endl;
    return 0;
}