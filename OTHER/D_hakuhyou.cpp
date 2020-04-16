#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 90;
const int MAX_W = 90;
int W, H;

int field[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];

int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};

int bfs(int y, int x, int tot)
{
    dist[y][x] = tot;

    int max_dist = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // field外ならcontinue;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W)
            continue;
        // 探索済みならcontinue;
        if (dist[ny][nx] != -1)
            continue;
        // 氷じゃないならcontinue;
        if (field[ny][nx] == 0)
            continue;

        max_dist = max(max_dist, bfs(ny, nx, tot + 1));
        dist[ny][nx] = -1;
    }
    tot = max(max_dist, tot);
    return tot;
}

void reset_dist()
{
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            dist[y][x] = -1;
        }
    }
}

int main()
{
    cin >> W >> H;

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            cin >> field[y][x];
            dist[y][x] = -1;
        }
    }

    int ans = 0;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            // (y, x)が氷かつ未訪問ならばbfs
            if (field[y][x] == 1)
            {
                ans = max(ans, bfs(y, x, 1));
            }
            reset_dist();
        }
    }

    cout << ans << endl;
}