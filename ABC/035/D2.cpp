#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
const int INF = 1e+9;

const int MAX_N = 100000;

vector<int> dijkstra(int N, vector<P> G[], int s)
{
    vector<int> dist(N, INF);
    bool fixed[MAX_N] = {false};
    priority_queue<P, vector<P>, greater<P>> que;

    dist[s] = 0;
    que.push(P(s, 0));

    while (!que.empty())
    {
        int t, d;
        tie(t, d) = que.top();
        que.pop();

        if (fixed[t])
            continue;
        fixed[t] = true;
        if (dist[t] < d)
            continue;

        for (P e : G[t])
        {
            int to, cost;
            tie(to, cost) = e;
            if (dist[to] > dist[t] + cost)
            {
                dist[to] = dist[t] + cost;
                que.push(P(to, dist[to]));
            }
        }
    }

    return dist;
}

int main()
{
    ll N, M;
    ll T;
    cin >> N >> M >> T;

    long long A[N];
    rep(i, N) cin >> A[i];

    vector<P> G[MAX_N];
    vector<P> r_G[MAX_N];
    rep(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        G[a].push_back(P(b, c));
        r_G[b].push_back(P(a, c));
    }
    vector<int> d = dijkstra(N, G, 0);
    vector<int> r_d = dijkstra(N, r_G, 0);

    ll ans = 0;
    rep(i, N)
    {
        ans = max(ans, (T - d[i] - r_d[i]) * A[i]);
    }

    cout << ans << endl;
    return 0;
}