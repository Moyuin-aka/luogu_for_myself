#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

long long mod(long long a, long long b)
{
    return (a % b + b) % b;
}

int main()
{
    // 这个题还是很奇葩的，xmodn，ymodm来确认道路类型
    // 说明原来的x，y可能远大于n，m，做mod运算压缩到0~n-1，0~m-1
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        pair<int, int> start;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    start = {i, j};
                }
            }
        }
        // 从起点做bfs遍历
        vector<vector<char>>visited(n, vector<char>(m, 0));
        vector<vector<long long>>ox(n, vector<long long>(m, 0));
        vector<vector<long long>>oy(n, vector<long long>(m, 0));
        queue<pair<long long, long long>> q;
        q.push(start);
        bool out=false;
        while(!q.empty()&&!out){
            auto [x,y]=q.front();q.pop();
            if(grid[mod(x,n)][mod(y,m)]=='#')continue;
            int i=mod(x,n),j=mod(y,m);
            long long tx=(x-i)/n; //所以就定义了平铺块的坐标 (t_x, t_y)：
            //t_x = \frac{x - i}{n}, \quad t_y = \frac{y - j}{m}.
            long long ty=(y-j)/m;

            // 第一次见到这个模格子：登记“所有权”为当前平铺块
            if(visited[i][j]==0){
                visited[i][j]=1;
                ox[i][j]=tx;
                oy[i][j]=ty;
            }
            else{
                // 不是第一次见到这个模格子
                // 如果当前平铺块和登记的平铺块不同，说明走出了边界
                if(ox[i][j]!=tx||oy[i][j]!=ty){
                    out=true;
                    break;
                }
                else continue;
            }
            // 四个方向扩展
            q.push({x+1,y});
            q.push({x-1,y});
            q.push({x,y+1});
            q.push({x,y-1});
        }
        cout<<(out?"Yes":"No")<<endl;
    }
    return 0;
}