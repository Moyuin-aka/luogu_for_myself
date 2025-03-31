#include <bits/stdc++.h>
using namespace std;

struct node
{
    int id;
    node *left;
    node *right;
    node(int id) : id(id), left(NULL), right(NULL) {}
};

int getDepth(node *root)
{
    if (root == NULL)
        return 0;
    return max(getDepth(root->left), getDepth(root->right)) + 1; // 递归，+1是因为要加上自己的这一层
}
//树的绝大多数问题可以写成 f(当前节点) = f(左子树) + f(右子树) + 自己这一层做的事


int main()
{
    int n;
    cin >> n;
    int i=0;
    vector<node *> tree(n + 1,nullptr);
    for (int i = 1; i <= n; i++)
    {
        tree[i] = new node(i);
    }
    //这里得先创建节点，才能给节点赋值，不然之后赋值全是nullptr
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l != 0)
            tree[i]->left = tree[l];
        if (r != 0)
            tree[i]->right = tree[r];
    }
    // 构造完成开遍历
    int depth = getDepth(tree[1]);
    cout << depth << endl;
    // 释放内存
    for (int i = 1; i <= n; i++)
    {
        delete tree[i];
    }
    return 0;
}
