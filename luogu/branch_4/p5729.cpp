#include <iostream>
using namespace std;

int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int q;
    cin >> q;

    // 记录总的体积
    int totalVolume = w * x * h;

    // 使用差分数组记录切割的体积
    int cuts[100][100][100] = {0}; // 假设最大尺寸为100

    for (int i = 0; i < q; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // 进行切割的标记
        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                for (int l = z1; l <= z2; l++)
                {
                    cuts[j][k][l] = 1; // 标记为已切割
                }
            }
        }
    }

    // 计算被切割的小方块的数量
    int cutVolume = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                cutVolume += cuts[i][j][k]; // 统计已切割的体积
            }
        }
    }

    // 计算剩余体积
    int remainingVolume = totalVolume - cutVolume;
    cout << remainingVolume << endl;

    return 0;
}
