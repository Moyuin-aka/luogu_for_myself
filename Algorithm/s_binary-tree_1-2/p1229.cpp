#include<bits/stdc++.h>
using namespace std;
//ai 给的观察规律：当前序遍历的字母在后序遍历依然与某不变字母相邻，统计该字母的数量，然后用2^n次方即可得到中序序列。
int main(){
    string pre,post;
    cin>>pre>>post;
    vector<int>chars(26,0);
    for(int i=0;i<post.length();i++){
        chars[post[i]-'a']=i;
    }
    //记录出现位置？
   long long count=1;
   for(int i=0;i<pre.length()-1;i++){
    if(chars[pre[i+1]-'a']+1==chars[pre[i]-'a']) //如果前序遍历的该字符的下一个（即假设为不变字符）的后序遍历中下一个,依然为该字符，那就可以看作满足字母需求
    count*=2;
   } 
   cout<<count;
   return 0;
}



/*struct Node{
    char c;
    Node* left;
    Node* right;
    Node(){c='1';left=right=nullptr;};
};
long long cause=0;
void middleorder(Node*root){
    if(root==nullptr) return;

}
int main(){
    string pre;
    string after;
    cin>>pre>>after;


}*/