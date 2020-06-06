#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int V, E;
int const max_v = 20;
const int INF = 100000000;
vector<int> G[max_v];
int C[max_v][max_v];

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
        int from, to, cost;
        cin >> from >> to >> cost;
        C[from][to] = cost;
    }

    // DPの初期化
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    // DP開始
    // S = 10010などすでに訪れた頂点を示す
    for (int S = 0; S < (1 << V); S++)
    {
        //v = 次に訪れる頂点
        for (int v = 0; v < V; v++)
        {
            for (int u = 0; u < V; u++)
            {
                if ((S & (1 << v)) == 0 || v == u)
                {
                    continue;
                }
                dp[S][v] = min(dp[S][v], dp[S & ~(1 << v)][u] + C[u][v]);
                /*
                if ((S & (1 << v)) == 0 && C[u][v] != INF)
                {
                    dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u] + C[u][v]);
                }
                */
            }
        }
    }

    if (dp[(1 << V) - 1][0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[(1 << V) - 1][0] << endl;
    }
    return 0;
}