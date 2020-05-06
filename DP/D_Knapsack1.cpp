#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, W;
    cin >> N >> W;

    ll value[N];
    ll weight[N];

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    ll dp[N + 10][W + 10];
    fill(dp[0], dp[N + 10], -1);
    for (int i = 0; i < W + 9; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]);
            }
            else
            {
                dp[i + 1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}