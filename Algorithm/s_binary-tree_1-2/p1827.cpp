#include<bits/stdc++.h>
using namespace std;
//二叉树的中序遍历和前序遍历结合得到 唯一二叉树，我们要做的就是还原这棵树然后对它进行后序遍历
void order(string pre,string in){

    if(pre.size()==0||in.size()==0)return;//如果前序遍历 or 中序遍历都为空，说明没有树了

    char root=pre[0];//前序遍历的第一个元素就是根节点
    int pos=in.find(root);//在中序遍历中找到根节点的位置

    string left_in=in.substr(0,pos);//左子树的中序遍历
    string right_in=in.substr(pos+1);//右子树的中序遍历

    //这里的字符串截取或许很让人费解，但是很好理解
    //因为中序遍历是 左->根->右，且前序遍历的第一个元素必然是根结点，那么中序遍历里
    //左->根 的字符串就算左子树，而根->右的字符串就算右子树，递归后会压成一个二叉树的左叶子和右叶子

    string left_pre=pre.substr(1,left_in.length());//左子树的前序遍历
    string right_pre=pre.substr(left_in.length()+1);//右子树的前序遍历

    //这里的前序遍历也比较难以理解，但一样
    //前序遍历是 根->左->右，而我们已经知道了根结点，所以前序遍历的第一个元素就是根结点，第二个元素就是左子树根结点，就可以这样构造下一个前序遍历的开头
    //那截取到什么地方呢？这里要请中序遍历出场了，中序遍历给了下一个左子树的节点个数，刚好，前序遍历本来就是 根->左->右 的
    //第二个元素为左根结点，假设左子树有n个结点，那么从pre[1]到pre[n]就是左子树的前序遍历
    //而右子树的前序遍历就是从pre[n+1]到最后一个元素了
    //递归后会压成一个二叉树的左叶子和右叶子，然后先输出唯一的左结点，后输出唯一的右结点，最后输出根，恰好就算后序遍历

    order(left_pre,left_in);//递归左子树
    order(right_pre,right_in);//递归右子树  
    cout<<root;//输出根节点

    //后序遍历是先左边读完再右边读完最后再读根，这个递归压缩做到了
}
int main(){
    string pre,in;
    cin>>in>>pre;
    order(pre,in);//调用函数,还原一下二叉树,然后按照左->右->根的顺序输出
    return 0;
}