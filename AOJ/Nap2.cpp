#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    int dp[N + 10][W + 10];
    for (int w = 0; w <= W; w++)
    {
        dp[0][w] = 0;
    }

    int weight[N], value[N];
    for (int i = 0; i < N; i++)
    {
        cin >> value[i] >> weight[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                dp[i + 1][w] = max(dp[i + 1][w - weight[i]] + value[i], dp[i][w]);
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