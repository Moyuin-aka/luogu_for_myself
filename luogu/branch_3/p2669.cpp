#include <iostream>
using namespace std;
int getRelation(int n);
int calSum(int k);
int main()
{
    int k;
    cin >> k;
    int result=calSum(k);
    cout<<result;
    return 0;
}
int getRelation(int n){
    if(n<=0){
        return 0;
    }
    int group=1;
    int count=1;
    while(n>count){
        n-=count;
        group++;
        count++;
    }
    return group;
    }
int calSum(int k){
    int total=0;
    for(int i=1;i<=k;i++){
        total+=getRelation(i);
    }
    return total;
}