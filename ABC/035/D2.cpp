#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
const int INF = 1e+9;

const int MAX_N = 100005;

void dijkstra(vector<int> &dist, vector<P> G[], int s)
{
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

        for (P e : G[t])
        {
            int to, cost;
            tie(to, cost) = e;
            dist[to] = min(dist[to], dist[t] + cost);
            que.push(P(to, dist[to]));
        }
    }

    return;
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
    vector<int> d(N, INF);
    vector<int> r_d(N, INF);

    dijkstra(d, G, 0);
    dijkstra(r_d, r_G, 0);

    ll ans = 0;
    rep(i, N)
    {
        ll tot = A[i] * (T - d[i] - r_d[i]);
        ans = max(ans, tot);
    }

    cout << ans << endl;
    return 0;
}