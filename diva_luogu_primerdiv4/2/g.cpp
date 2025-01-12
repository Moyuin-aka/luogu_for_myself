#include<bits/stdc++.h>
using namespace std;

bool changeToTri(int a,int b, int c){
    return a+c>b&&a+b>c&&b+c>a;
}

bool isTri(int x){
    vector<int>nums;
    while(x>0){
        if(x%10==0)return false;
        nums.push_back(x%10);
        x/=10;
    }
    return 
    (changeToTri(nums[0], nums[1], nums[2]) && changeToTri(nums[3], nums[4], nums[5])
    || changeToTri(nums[0], nums[1], nums[3]) && changeToTri(nums[2], nums[4], nums[5])
    || changeToTri(nums[0], nums[2], nums[3]) && changeToTri(nums[1], nums[4], nums[5])
    || changeToTri(nums[0], nums[1], nums[4]) && changeToTri(nums[2], nums[3], nums[5])
    || changeToTri(nums[0], nums[1], nums[5]) && changeToTri(nums[2], nums[3], nums[4])
    || changeToTri(nums[0], nums[2], nums[4]) && changeToTri(nums[1], nums[3], nums[5])
    || changeToTri(nums[0], nums[2], nums[5]) && changeToTri(nums[1], nums[3], nums[4])
    || changeToTri(nums[0], nums[3], nums[4]) && changeToTri(nums[1], nums[2], nums[5])
    || changeToTri(nums[0], nums[3], nums[5]) && changeToTri(nums[1], nums[2], nums[4])
    || changeToTri(nums[0], nums[4], nums[5]) && changeToTri(nums[1], nums[2], nums[3])
    );
}

int main(){
    int x,y;
    cin>>x>>y;
    int count=0;
    for(int i=x;i<=y;i++){
        if(isTri(i)) count++;
    }
    cout<<count<<endl;
}