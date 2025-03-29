#include<bits/stdc++.h>
using namespace std;
struct tree{
    int id,power;
    tree* loser=nullptr;
    tree* winner=nullptr;
};
tree* buildTree(vector<tree*>&country,int l,int r){//这个是冠军结点的遍历，要找到它后找到输给它的亚军,l和r分别是这个组的左边界和右边界
    if(l==r){
        return country[l];//如果l==r，说明只有一个结点来参与比赛了，而这个结点就是冠军结点
    }
    int mid=(l+r)/2; //这个是二分法的思想，找到中间的结点，虽然有点难以理解....题目里是相邻的两个结点打比赛，实际上是把所有的结点分成两组，然后分别打比赛，最后再把两组的冠军进行比赛
    tree* left=buildTree(country,l,mid);//左边的组
    tree* right=buildTree(country,mid+1,r);//右边的组
    //这些递归最终会被压缩成相邻的两个结点打比赛...
    if(left->power>right->power){//如果左边的组的冠军比右边的组的冠军强，那么左边的组的冠军就是这个组的冠军，右边的组的冠军就是这个组的亚军
        left->winner=left;
        left->loser=right;
        return left;
    }else{//如果右边的组的冠军比左边的组的冠军强，那么右边的组的冠军就是这个组的冠军，左边的组的冠军就是这个组的亚军
        right->winner=right;
        right->loser=left;
        return right;
    }
}
int main(){
    int n;
    cin>>n;
    vector<tree*>country(pow(2,n));
    for(int i=0;i<pow(2,n);i++){
        country[i]=new tree;
        cin>>country[i]->power;
        country[i]->id=i+1;
    }
    tree* champion=buildTree(country,0,pow(2,n)-1);
    cout<<champion->loser->id<<endl;//输出亚军的id
    return 0;
}
