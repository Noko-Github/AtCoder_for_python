#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int H = 10;
const int W = 10;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

string field[H];
bool seen[H][W] = {false};
bool reset_seen[H][W] = {false};

void dfs(int y, int x)
{

    int nx, ny;
    rep(i, 4)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] == 'x')
            continue;

        if (!seen[ny][nx])
        {
            seen[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main()
{
    rep(i, H) cin >> field[i];

    rep(i, H)
    {
        rep(j, W)
        {
            int count = 0;
            if (field[i][j] == 'x')
            {
                field[i][j] = 'o';
                rep(y, H)
                {
                    rep(x, W)
                    {
                        if (!seen[y][x] && field[y][x] == 'o')
                        {
                            count++;
                            seen[y][x] = true;
                            dfs(y, x);
                        }
                    }
                }
                rep(l, H)
                {
                    rep(m, W)
                    {
                        seen[l][m] = false;
                    }
                }
                field[i][j] = 'x';
            }

            if (count == 1)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}