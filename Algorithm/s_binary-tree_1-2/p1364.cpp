#include<bits/stdc++.h>
using namespace std;

struct Node
{
    //二叉树id，居民人口,左右结点
    int people;
    int left,right;
    int parent;
    Node():people(0),left(0),right(0){}
};

vector<int>calDist(int start,vector<Node>&tree){
    vector<int>dist(tree.size(),-1);
    //找医院与其他结点的距离
    queue<int>q; //用到队列，是BFS遍历哦
    q.push(start);
    dist[start]=0;
    //利用队列先进先出来计算
    while(!q.empty()){ //q不空的时候，说明前面还有要统计的序列
        int cur=q.front();//目前要被计入的结点
        q.pop();

        //检查左结点
        if(tree[cur].left!=0&&dist[tree[cur].left]==-1){
            //如果左结点存在并且还没统计过它，加一下它距离start的值，如果没统计过加一下它，因为对于左结点来说，它距离那个start是有个父节点的距离（如果记过就不要记了）
            dist[tree[cur].left]=dist[cur]+1;
            q.push(tree[cur].left); //邻居入队
        }
         // 检查右
         if (tree[cur].right > 0 && dist[tree[cur].right] == -1) {
            dist[tree[cur].right] = dist[cur] + 1;
            q.push(tree[cur].right);
        }
        
        // 检查父
        if (tree[cur].parent > 0 && dist[tree[cur].parent] == -1) {
            dist[tree[cur].parent] = dist[cur] + 1;
            q.push(tree[cur].parent);
        }
        // 检查父确实容易漏，start不一定是根结点，所以得看一下一个结点连接的所有点
    
    }
    return dist;
}

int PeopleDist(int start,vector<Node>&tree){
  vector<int>dist=calDist(start,tree);
  int total=0;
  for(int i=1;i<tree.size();i++){
    total+=dist[i]*(tree[i].people);
  }
  return total;
}
int main(){
    int n;
    cin>>n;
    vector<Node>tree(n+1);//题目坑，编号从1开始
    for(int i=1;i<=n;i++){
        cin>>tree[i].people>>tree[i].left>>tree[i].right;
        if(tree[i].left!=0) tree[tree[i].left].parent=i;
        if(tree[i].right!=0) tree[tree[i].right].parent=i;
    }
    int minDist=INT_MAX;
    for(int i=1;i<=n;i++){
        minDist=min(minDist,PeopleDist(i,tree));
    }
    cout<<minDist<<endl;
    //system("pause");
    return 0;
}
