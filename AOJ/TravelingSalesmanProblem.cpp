#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 10000000000000;
const int MAX_V = 15;
vector<vector<ll>> G(MAX_V, vector<ll>(MAX_V, INF));
vector<vector<ll>> dp(1 << MAX_V, vector<ll>(MAX_V, -1));

int V, E;

ll dfs(ll S, int v)
{

    if (dp[S][v] >= 0)
    {
        return dp[S][v];
    }

    if (S == (1 << V) - 1 && v == 0)
    {
        dp[S][v] = 0;
        return dp[S][v];
    }

    ll ans = INF;
    for (int u = 0; u < V; u++)
    {
        if (!(S >> u & 1))
        {
            ans = min(ans, dfs(S | 1 << u, u) + G[v][u]);
        }
    }
    dp[S][v] = ans;
    return ans;
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        G[from][to] = cost;
    }

    ll ans = 0;
    ans = dfs(0, 0);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}