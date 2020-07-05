#include <bits/stdc++.h>
using namespace std;
const int WALL = 5;
int main()
{
    int W, H;
    cin >> W >> H;
    int M_W = W + W - 1;
    int M_H = H + H - 1;
    int field[M_H][M_W];
    for (int y = 0; y < M_H; y++)
    {
        for (int x = 0; x < M_W; x++)
        {
            field[y][x] = 0;
        }
    }

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W - 1; x++)
        {
            int cell;
            cin >> cell;
            if (cell == 1)
            {
                field[2 * y][x * 2 + 1] = WALL;
            }
        }
        if (y == H - 1)
        {
            break;
        }
        for (int x = 0; x < W; x++)
        {
            int cell;
            cin >> cell;
            if (cell == 1)
            {
                field[2 * y + 1][x * 2] = WALL;
            }
            // cout << y << endl;
            // if ((y * 2 + 1) % 2 == 1 && x % 2 == 0)
            // {
            //     field[2 * y + 1][x * 2 + 1] = WALL;
            // }
        }
    }

    // 確認
    for (int y = 0; y < M_H; y++)
    {
        for (int x = 0; x < M_W; x++)
        {
            cout << field[y][x];
        }
        cout << endl;
    }
    return 0;
}