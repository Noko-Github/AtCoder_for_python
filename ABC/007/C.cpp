#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int MAX_H = 50;
const int MAX_W = 50;
int dist[MAX_H][MAX_W];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < MAX_H; i++)
    {
        for (int j = 0; j < MAX_W; j++)
        {
            dist[i][j] = -1;
        }
    }

    int sx, sy, gx, gy;
    string field[H];
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    for (int i = 0; i < H; i++)
    {
        cin >> field[i];
    }

    dist[sy][sx] = 0;
    queue<P> que;
    que.push(P(sy, sx));
    while (!que.empty())
    {
        int y, x;
        tie(y, x) = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny, nx;
            ny = y + dy[i];
            nx = x + dx[i];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                continue;
            if (field[ny][nx] == '#')
                continue;
            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push(P(ny, nx));
        }
    }

    cout << dist[gy][gx] << endl;
    return 0;
}