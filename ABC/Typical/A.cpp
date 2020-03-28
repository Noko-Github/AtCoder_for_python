#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int H, W;
const int MAX_H = 500;
const int MAX_W = 500;
vector<string> field;
bool passed[MAX_H][MAX_W] = {false};

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    rep(i, 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] == '#')
            continue;
        if (!passed[ny][nx])
        {
            passed[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> H >> W;
    field.resize(H);
    rep(i, H) cin >> field[i];

    int sy, sx, gy, gx = 0;
    rep(y, H)
    {
        rep(x, W)
        {
            if (field[y][x] == 's')
            {
                sy = y;
                sx = x;
            }
            if (field[y][x] == 'g')
            {
                gy = y;
                gx = x;
            }
        }
    }

    dfs(sy, sx);

    if (passed[gy][gx])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}