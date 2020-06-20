#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
const ll INF = 100000000000;

int main()
{
    cin >> N >> M;
    ll dist[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        dist[a][b] = cost;
        dist[b][a] = cost;
    }

    for (int i = 0; i < N; i++)
    {
        dist[i][i] = 0;
    }

    // ワーシャルフロイド
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < N; i++)
    {
        ll tmp = 0;
        for (int j = 0; j < N; j++)
        {
            tmp = max(tmp, dist[i][j]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}