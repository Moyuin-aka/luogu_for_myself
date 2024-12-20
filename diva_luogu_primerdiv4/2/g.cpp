#include<bits/stdc++.h>
using namespace std;
bool tri(int a,int b,int c){
    return a+b>c&&a+c>b&&b+c>a;
}
bool twotri(vector<int>&arr){
    sort(arr.begin(),arr.end());
    do{
    vector<int>g1={arr[0],arr[1],arr[2]};
    vector<int>g2={arr[3],arr[4],arr[5]};
    if(tri(g1[0],g1[1],g1[2])&&tri(g2[0],g2[1],g2[2])){
        return true;
        }
    }while(next_permutation(arr.begin(),arr.end()));
    return false;
}
int main(){
    int begin,end;
    cin>>begin>>end;
    int count=0;
    for(int i=begin;i<=end;i++){
        vector<int>arr(6);
        int num=i;
        for(int j=0;j<6;j++){
            arr[j]=num%10;
            num/=10;
            }
            if(twotri(arr)){
                count++;
            }
        }
    cout<<count;
    return 0;
}