#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000;

int main()
{
    int n, m;
    cin >> n >> m;
    int coins[n + 5];
    for (int i = 1; i <= m; i++)
    {
        cin >> coins[i];
    }

    int dp[m + 5][n + 5];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (coins[i] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
