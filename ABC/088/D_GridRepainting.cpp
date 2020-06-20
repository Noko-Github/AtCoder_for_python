#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAX_H = 50;
const int MAX_W = 50;
string field[MAX_H];
int dist[MAX_H][MAX_W];
int H, W;

int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};

bool bfs(int x, int y)
{
    queue<P> que;
    que.push(P(y, x));

    while (!que.empty())
    {

        tie(y, x) = que.front();
        que.pop();
        if (y == H - 1 && x == W - 1)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            // field外
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] == '#')
                continue;
            // 既に探索済み
            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push(P(ny, nx));
        }
    }

    return false;
}

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        cin >> field[i];
    }

    // 初期化+黒マスの数をカウント
    int cnt_white = 0;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            dist[y][x] = -1;
            if (field[y][x] == '.')
            {
                cnt_white++;
            }
        }
    }

    // bfs
    dist[0][0] = 0;
    if (!bfs(0, 0))
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << cnt_white - 1 - dist[H - 1][W - 1] << endl;
    }

    return 0;
}