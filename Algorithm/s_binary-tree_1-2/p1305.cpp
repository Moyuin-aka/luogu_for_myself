#include<bits/stdc++.h>
using namespace std;
struct Node{
    char a;
    Node *left;
    Node *right;
    Node(char c){
        a=c;
        left=right=nullptr;
    };
};

void preorder(Node *root){
    if(root==nullptr) return;
    cout<<root->a;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cin>>n;
    vector<Node*>nodes(26);
    for(int i=0;i<26;i++){
        nodes[i]=new Node('a'+i);
    }
    Node *root=nullptr;
    for(int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        //nodes[a-'a']->a=a;
        if(b!='*')
        nodes[a-'a']->left=nodes[b-'a'];
        if(c!='*') nodes[a-'a']->right=nodes[c-'a'];
        if(i==0) root=nodes[a-'a'];
    }
    preorder(root);
    for(auto node:nodes) delete node;
    return 0;
}