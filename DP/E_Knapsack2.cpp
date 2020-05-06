#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18 + 10;

int main()
{
    ll N, W;
    cin >> N >> W;

    ll value[N];
    ll weight[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    vector<vector<ll>> dp(N + 10, vector<ll>(100000 + 10, INF));
    dp[0][0] = 0;

    for (ll i = 0; i < N; i++)
    {
        for (ll sum_v = 0; sum_v <= 100010; sum_v++)
        {
            if (sum_v >= value[i])
            {
                dp[i + 1][sum_v] = min(dp[i][sum_v], dp[i][sum_v - value[i]] + weight[i]);
            }
            else
            {
                dp[i + 1][sum_v] = dp[i][sum_v];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 100010; i++)
    {
        if (dp[N][i] <= W)
        {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}