#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    int H[N][3];

    for (int i = 0; i < N; i++)
    {
        cin >> H[i][0] >> H[i][1] >> H[i][2];
    }

    ll dp[N][3];
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    dp[0][0] = H[0][0];
    dp[0][1] = H[0][1];
    dp[0][2] = H[0][2];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j == k)
                    continue;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + H[i + 1][k]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, dp[N - 1][i]);
    }
    cout << ans << endl;
    return 0;
}