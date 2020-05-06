#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dy[2] = {0, 1};
int dx[2] = {1, 0};

ll const MOD = 1e+9 + 7;

int main()
{
    int H, W;
    cin >> H >> W;
    string field[H];
    for (int h = 0; h < H; h++)
    {
        cin >> field[h];
    }

    ll dp[1010][1010] = {0};

    dp[0][0] = 1;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            for (int k = 0; k < 2; k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < H && nx < W && field[ny][nx] == '.')
                {
                    dp[ny][nx] = (dp[ny][nx] + dp[y][x]) % MOD;
                }
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
    return 0;
}