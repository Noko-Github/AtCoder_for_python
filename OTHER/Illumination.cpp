#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int H, W;

bool used[1010][1010] = {false};
bool field[1010][1010];

ll ans = 0;

int oy[6] = {-1, -1, 0, 1, 1, 0};
int ox[6] = {0, 1, 1, 1, 0, -1};
int ey[6] = {-1, -1, 0, 1, 1, 0};
int ex[6] = {-1, 0, 1, 0, -1, -1};

void bfs(int y, int x)
{
    queue<P> que;
    que.push(P(y, x));

    while (!que.empty())
    {
        int y, x;
        tie(y, x) = que.front();
        que.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx, ny;
            if (y % 2 == 0)
            {
                ny = ey[i] + y;
                nx = ex[i] + x;
            }
            else
            {
                ny = oy[i] + y;
                nx = ox[i] + x;
            }
            // 範囲外であればcontinue
            if (ny < 0 || ny >= H + 1 || nx < 0 || nx >= W + 1 || used[ny][nx])
                continue;

            // 壁があったらカウント
            if (field[ny][nx] == 1)
            {
                ans++;
                continue;
            }

            // 普通のますならばpush
            used[ny][nx] = true;
            que.push(P(ny, nx));
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
            cin >> field[y + 1][x + 1];
        }
    }

    for (int i = 0; i < 1010; i++)
    {
        for (int j = 0; j < 1010; j++)
        {
            used[i][j] = false;
        }
    }
    H += 2;
    W += 2;

    used[0][0] = true;
    bfs(0, 0);

    cout << ans << endl;
    return 0;
}