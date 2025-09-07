#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//依次读入每个杂务的工作说明。计算出所有杂务都被完成的最短时间。
// 互相没有关系的杂务可以同时工作
// 有些杂务必须在另一些杂务完成的情况下才能进行。
// 有需要完成的 n 个杂务的清单，并且这份清单是有一定顺序的，杂务 k (k>1) 的准备工作只可能在杂务 1 至 k−1 中。
// 一道拓扑排序题，找到所有入度为0的点，更新其邻接点的入度，直到所有点都被更新完，但是并行计算时间是一个难点……
// 有些任务不需要第二个任务完成，但是下一个任务需要第二个和第三个共同完成，且第二个任务完成时间比第三个短的话，特殊任务不能计入计算……
// 难点是找到并行时间最大值。

struct task
{
    int id;
    int time;
    vector<int>next;
    int inDegree=0;
};

int main(){
    int n;
    cin>>n;
    vector<task>tasks(n+1);
    for(int i=1;i<=n;i++){
        int id,t;
        cin>>id>>t;
        tasks[id].id=id;
        tasks[id].time=t;
        int k=-1;
        while(cin>>k,k!=0){
            tasks[k].next.push_back(id);
            tasks[id].inDegree++;
        }
    }
    vector<int>start(n+1,0); // 每个任务的最早开工时间，我该做线性统计而非归并计算……

    vector<int>end(n+1,0); // 完成每个任务的最早时间
    for(int i=1;i<=n;i++){
        if(tasks[i].inDegree==0){
            end[i]=start[i]+tasks[i].time;
            for(int v:tasks[i].next){
                start[v]=max(start[v],end[i]);
                tasks[v].inDegree--;
            }
            //当入度为0，可以和现有线性时间的标记终止时间做比较了……
        }
    } 
    //最后终止的时间就是最短时间。把时间当作线性看待是关键。
    cout<<*max_element(end.begin(),end.end())<<endl;
    return 0;

}