#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;

int main()
{
    int H, W;
    cin >> H >> W;

    int dist[10][10];
    int min_dist[10][10];
    for (int i = 0; i <= 9; i++)
    {

        for (int j = 0; j <= 9; j++)
        {
            cin >> dist[i][j];
            min_dist[i][j] = INF;
            if (i == j)
            {
                min_dist[i][i] = 0;
            }
        }
    }

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int isNumber;
            cin >> isNumber;
            if (isNumber != -1)
            {
                ans += dist[isNumber][1];
            }
        }
    }

    cout << ans << endl;

    return 0;
}