/*# P3884 [JLOI2009] 二叉树问题*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int d):data(d),left(NULL),right(NULL){}
    Node(int d,Node* l,Node* r):data(d),left(l),right(r){}
    Node():data(0),left(NULL),right(NULL){}
};

void insert(vector<Node*>&tree,int u,int v){
    if(tree[u]==NULL){
        tree[u]=new Node(u);
    }
    if(tree[v]==NULL){
        tree[v]=new Node(v);
    }
    if(tree[u]->left==NULL){
        tree[u]->left=tree[v];
    }else{
        tree[u]->right=tree[v];
    }
}
int depth(Node* root){
    if(root==nullptr) return 0;
    return max(depth(root->left),depth(root->right))+1;
}
int width(Node* root){
    //层序遍历，期中考过
    if(root==nullptr) return 0;
    queue<Node*>q;
    q.push(root);
    int maxWidth=0;
    while(!q.empty()){
        int size=q.size();               
        maxWidth=max(maxWidth,size);
        for(int i=0;i<size;i++){
            Node* p=q.front();//队列头节点取出做递归
            q.pop();
            if(p->left!=nullptr) q.push(p->left);
            if(p->right!=nullptr) q.push(p->right);
        }
    }
    return maxWidth;
}
// 找到节点在树中的路径
bool findPath(Node* root, int target, vector<Node*>& path) {
    if (root == nullptr) return false;
    
    // 添加当前节点到路径
    path.push_back(root);
    
    // 如果找到目标节点
    if (root->data == target) return true;
    
    // 在左子树或右子树中查找
    if ((root->left && findPath(root->left, target, path)) || 
        (root->right && findPath(root->right, target, path)))
        return true;
    
    // 如果当前路径不包含目标节点，则回溯
    path.pop_back();
    return false;
}

// 计算两个节点之间的距离
int distance(Node* root, int x, int y) {
    // 存储从根到x和y的路径
    vector<Node*> path_x, path_y;
    
    // 找到路径
    if (!findPath(root, x, path_x) || !findPath(root, y, path_y)) {
        return -1; // 节点不存在
    }
    
    // 找到最近公共祖先(LCA)的索引
    int lca_idx = 0;
    while (lca_idx < path_x.size() && lca_idx < path_y.size() && 
           path_x[lca_idx] == path_y[lca_idx]) {
        lca_idx++;
    }
    lca_idx--; // 调整为实际的LCA索引
    
    // 计算距离：从x到LCA的距离*2 + 从LCA到y的距离
    int dist_x_to_lca = path_x.size() - 1 - lca_idx; // x到LCA的边数
    int dist_lca_to_y = path_y.size() - 1 - lca_idx; // LCA到y的边数
    
    // 应用规则：向上走一步+2，向下走一步+1
    return dist_x_to_lca * 2 + dist_lca_to_y;
}
int main(){
    int n;
    cin>>n;
    vector<Node*>tree(n+1,nullptr);
    for(int i=1;i<=n-1;i++){
        int u,v;//起点，终点
        cin>>u>>v;
        insert(tree,u,v);
    }
    //深度输出
    cout<<depth(tree[1])<<endl;
    //宽度输出
    cout<<width(tree[1])<<endl;
    //距离输出
    int x,y;
    cin>>x>>y;
    cout<<distance(tree[1],x,y)<<endl;
    return 0;
}
/*
## 题目描述

如下图所示的一棵二叉树的深度、宽度及结点间距离分别为：

- 深度：$4$
- 宽度：$4$
- 结点 8 和 6 之间的距离：$8$
- 结点 7 和 6 之间的距离：$3$

其中宽度表示二叉树上同一层最多的结点个数，节点 $u, v$ 之间的距离表示从 $u$ 到 $v$ 的最短有向路径上向根节点的边数的两倍加上向叶节点的边数。

![](https://cdn.luogu.com.cn/upload/pic/6843.png)

给定一颗以 1 号结点为根的二叉树，请求出其深度、宽度和两个指定节点 $x, y$ 之间的距离。

## 输入格式

第一行是一个整数，表示树的结点个数 $n$。
接下来 $n - 1$ 行，每行两个整数 $u, v$，表示树上存在一条连接 $u, v$ 的边。
最后一行有两个整数 $x, y$，表示求 $x, y$ 之间的距离。

## 输出格式

输出三行，每行一个整数，依次表示二叉树的深度、宽度和 $x, y$ 之间的距离。

## 输入输出样例 #1

### 输入 #1

```
10
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
6 10
8 6
```

### 输出 #1

```
4
4
8
```

## 说明/提示

对于全部的测试点，保证 $1 \leq u, v, x, y \leq n \leq 100$，且给出的是一棵树。保证 $u$ 是 $v$ 的父结点。*/