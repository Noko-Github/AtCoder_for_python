#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int V, E;
ll const max_v = 20;
const ll INF = 1e18 + 10;
vector<int> G[max_v];
ll C[max_v][max_v];
ll TIME[max_v][max_v];

int main()
{
    int V, E;
    cin >> V >> E;

    //初期化
    for (int i = 0; i < max_v; i++)
    {
        for (int j = 0; j < max_v; j++)
        {
            if (i == j)
            {
                C[i][i] = 0;
            }
            else
            {

                C[i][j] = INF;
            }
        }
    }

    // グラフの入力
    for (int i = 0; i < E; i++)
    {
        ll from, to, cost, time;
        cin >> from >> to >> cost >> time;
        from--;
        to--;
        C[from][to] = cost;
        C[to][from] = cost;
        TIME[from][to] = time;
        TIME[to][from] = time;
    }

    // DPの初期化
    pair<ll, ll> dp[1 << V][V];
    for (ll i = 0; i < (1 << V); i++)
    {
        for (ll j = 0; j < V; j++)
        {
            dp[i][j] = make_pair(INF, 0);
        }
    }
    dp[0][0] = make_pair(0, 1);

    // DP開始
    // S = 10010などすでに訪れた頂点を示す
    for (ll S = 0; S < (1 << V); S++)
    {
        //v = 次に訪れる頂点
        for (ll v = 0; v < V; v++)
        {
            for (ll u = 0; u < V; u++)
            {
                //if ((S & (1 << v)) == 0 || v == u || dp[S & ~(1 << v)][u].first + C[u][v] > TIME[u][v])
                if ((S & (1 << v)) == 0 || v == u)
                {
                    continue;
                }
                /*
                if (S == 7)
                {
                    ll dist = dp[S & ~(1 << v)][u].first + C[u][v];
                    cout << "target is" << v << endl;
                    cout << "dist is " << dist << endl;
                    cout << "pre is " << dp[S][v].first << endl;
                    cout << "u pre is " << dp[S & ~(1 << v)][u].first << endl;
                    cout << "cost  is " << C[u][v] << endl;
                    cout << "limit" << TIME[u][v] << endl;
                    cout << "from " << u << endl;
                    cout << "to " << v << endl;
                    cout << bitset<11>(S) << endl;
                }
                */
                ll dist = dp[S & ~(1 << v)][u].first + C[u][v];
                ll count = dp[S & ~(1 << v)][u].second;
                if (dp[S & ~(1 << v)][u].first + C[u][v] > TIME[u][v])
                {
                    ll a = dp[S & ~(1 << v)][u].first;
                    ll b = C[u][v];
                    ll sum = a + b;
                    // cout << "sum is" << sum << endl;
                    // cout << "time is" << TIME[u][v] << endl;
                    // cout << "time is" << TIME[v][u] << endl;
                    // cout << " continued" << endl;
                    continue;
                }
                // cout << "-------------------" << endl;
                if (dp[S][v].first == dist)
                {
                    // cout << "dist is " << dist << endl;
                    // cout << "pre is " << dp[S][v].first << endl;
                    // cout << "u pre is " << dp[S & ~(1 << v)][u].first << endl;
                    // cout << "cost  is " << C[u][v] << endl;
                    // cout << "limit" << TIME[u][v] << endl;
                    // cout << bitset<11>(S) << endl;
                    dp[S][v].second = dp[S][v].second + count;
                }
                else if (dp[S][v].first > dist)
                {
                    dp[S][v] = make_pair(dist, count);
                }
                //dp[S][v].first = min(dp[S][v].first, dp[S & ~(1 << v)][u].first + C[u][v]);
                /*
                if ((S & (1 << v)) == 0 && C[u][v] != INF)
                {
                    dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u] + C[u][v]);
                }
                */
            }
        }
    }

    if (dp[(1 << V) - 1][0].first == INF)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dp[(1 << V) - 1][0].first << " ";
        cout << dp[(1 << V) - 1][0].second << endl;
    }
    return 0;
}