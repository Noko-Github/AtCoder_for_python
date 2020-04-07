#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 50;
const int MAX_W = 50;
int field[MAX_H][MAX_W];
int cnt;
int H, W;
// int dy[4] = {1, 0, -1, 0};
// int dx[4] = {1, 1, 0, -1};
bool seen[MAX_H][MAX_W];

void bfs(int y, int x)
{
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dy == 0 && dx == 0)
                continue;

            int ny = y + dy;
            int nx = x + dx;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                continue;
            if (field[ny][nx] == 0)
                continue;
            if (seen[ny][nx])
                continue;

            seen[ny][nx] = true;
            bfs(ny, nx);
        }
    }
}

int main()
{

    while (true)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            break;

        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                cin >> field[y][x];
            }
        }

        cnt = 0;
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                seen[y][x] = false;
            }
        }

        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                if (seen[y][x] || field[y][x] == 0)
                    continue;
                cnt++;
                seen[y][x] = true;
                bfs(y, x);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}