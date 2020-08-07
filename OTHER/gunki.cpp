#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<string> S(5, "");
    for (int i = 0; i < 5; i++)
    {
        cin >> S[i];
    }
    // 0=>R, 1=>B, 2=>W
    vector<map<char, int>> colors(N, map<char, int>());
    for (int col = 0; col < N; col++)
    {
        colors[col]['R'] = 0;
        colors[col]['W'] = 0;
        colors[col]['B'] = 0;
        for (int row = 0; row < 5; row++)
        {
            char color = S[row][col];
            colors[col][color]++;
        }
    }

    // for (int col = 0; col < N; col++)
    // {
    //     cout << colors[col]['R'] << " ";
    //     cout << colors[col]['B'] << " ";
    //     cout << colors[col]['W'] << endl;
    // }

    const ll INF = 1e18;
    vector<vector<ll>> dp(N + 10, vector<ll>(3, INF));
    dp[0][0] = 5 - colors[0]['R'];
    dp[0][1] = 5 - colors[0]['B'];
    dp[0][2] = 5 - colors[0]['W'];
    string COLOR = "RBW";
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == j)
                    continue;
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + ll(5 - colors[i + 1][COLOR[j]]));
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < 3; i++)
    {
        ans = min(ans, dp[N - 1][i]);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}