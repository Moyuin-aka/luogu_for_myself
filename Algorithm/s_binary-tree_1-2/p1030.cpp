/*# P1030 [NOIP 2001 普及组] 求先序排列*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string getPre(string in,string post){
    if(in.size()==0||post.size()==0)return "";//中序遍历和后序遍历都为空，说明树空。
    //后序遍历的最后一个元素就是根节点，中序遍历中根节点的左边是左子树，右边是右子树
    char root=post[post.size()-1];
    int pos=in.find(root);
    //递归找到左子树和右子树的结点
    string left_in=in.substr(0,pos);//左子树的中序遍历
    string right_in=in.substr(pos+1);//右子树的中序遍历
    string left_post=post.substr(0,left_in.size());//左子树的后序遍历
    string right_post=post.substr(left_in.size(),right_in.size());//右子树的后序遍历
    return root+getPre(left_in,left_post)+getPre(right_in,right_post);//根结点+左子树节点+右子树节点构成前序遍历，我们递归就是把一个一个的根节点找出来

}
int main(){
    string in,post;//中序，后序
    cin>>in>>post;
    string pre=getPre(in,post);
    cout<<pre<<endl;
    return 0;
}
/*
## 题目描述
给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，且二叉树的节点个数 $ \le 8$）。
## 输入格式
共两行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。
## 输出格式
共一行一个字符串，表示一棵二叉树的先序。
## 输入输出样例 #1
### 输入 #1
```
BADC
BDCA
```
### 输出 #1
```
ABCD
```
## 说明/提示
**【题目来源】**
NOIP 2001 普及组第三题*/