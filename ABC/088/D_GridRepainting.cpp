#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) cin >> field[i];

    vector<vector<int>> dist(H, vector<int>(W, -1));
    vector<vector<P>> prev(H, vector<P>(W));

    int sy, sx = 0;
    queue<P> que;
    que.push(P(sy, sx));
    dist[sy][sx] = 0;
    prev[0][0] = P(-1, -1);
    while (!que.empty())
    {
        int y, x;
        tie(y, x) = que.front();
        que.pop();

        int ny, nx;
        for (int i = 0; i < 4; i++)
        {
            ny = dy[i] + y;
            nx = dx[i] + x;

            if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] == '#')
                continue;

            if (dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                que.push(P(ny, nx));
                prev[ny][nx] = P(y, x);
            }
        }
    }

    int y = H - 1;
    int x = W - 1;
    vector<P> short_root;
    while (y != -1 && x != -1)
    {
        P d = prev[y][x];
        short_root.push_back(d);
        tie(y, x) = prev[y][x];
    }

    // for (int y = 0; y < H; y++)
    // {
    //     for (int x = 0; x < W; x++)
    //     {
    //         cout << dist[y][x] << " ";
    //     }
    //     cout << endl;
    // }

    // for (P d : short_root)
    // {
    //     int y, x;
    //     tie(y, x) = d;
    //     cout << "(y, x): " << y << " " << x << endl;
    // }

    int ans = 0;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (field[y][x] != '#')
            {
                bool ok = true;
                for (P d : short_root)
                {
                    int ng_y, ng_x;
                    tie(ng_y, ng_x) = d;
                    if (ng_y == y && ng_x == x)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    ans++;
            }
        }
    }
    if (dist[H - 1][W - 1] == -1)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << ans - 1 << endl;
    }

    return 0;
}