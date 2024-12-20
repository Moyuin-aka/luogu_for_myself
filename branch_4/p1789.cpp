#include <bits/stdc++.h>
using namespace std;
int pos[100][100];
bool border(int n, int boundary)
{
    if (n < 0 || n > boundary)
    {
        return false;
    }
    return true;
}
int main()
{
    int fire, stone, n;
    int count = 0;
    cin >> n >> fire >> stone;
    for (int i = 0; i < fire; i++)
    {
        int xf, yf;
        cin >> xf >> yf;
        xf--;
        yf--;
        if (border(xf, n) && border(yf, n))
        {
            pos[xf][yf] = 1;
            for (int j = 1; j <= 2; j++)
            {
                if (border(xf + j, n))
                    pos[xf + j][yf] = 1;
                if (border(xf - j, n))
                    pos[xf - j][yf] = 1;
                if (border(yf + j, n))
                    pos[xf][yf + j] = 1;
                if (border(yf - j, n))
                    pos[xf][yf - j] = 1;
            }
            if (border(xf + 1, n) && border(yf + 1, n))
                pos[xf + 1][yf + 1] = 1;
            if (border(xf + 1, n) && border(yf - 1, n))
                pos[xf + 1][yf - 1] = 1;
            if (border(xf - 1, n) && border(yf + 1, n))
                pos[xf - 1][yf + 1] = 1;
            if (border(xf - 1, n) && border(yf - 1, n))
                pos[xf - 1][yf - 1] = 1;
        }
    }
    for (int i = 0; i < stone; i++)
    {
        int xs, ys;
        cin >> xs >> ys;
        xs--;
        ys--;
        if (border(xs, n) && border(ys, n))
        {
            pos[xs][ys] = 1;
            for (int j = 0; j <= 2; j++)
            {
                for (int t = 0; t <= 2; t++)
                {
                    if (border(xs + j, n) && border(ys + t, n))
                        pos[xs + j][ys + t] = 1;
                    if (border(xs - j, n) && border(ys + t, n))
                        pos[xs - j][ys + t] = 1;
                    if (border(xs + j, n) && border(ys - t, n))
                        pos[xs + j][ys - t] = 1;
                    if (border(xs - j, n) && border(ys - t, n))
                        pos[xs - j][ys - t] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << pos[i][j];
            if (pos[i][j] == 0)
            {
                count++;
            }
        }
        cout << endl;
    }
    cout << count << endl;
    return 0;
}