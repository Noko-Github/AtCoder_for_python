#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
struct edge
{
    int to, dist, cost;
};
const int MAX_N = 1000000;
int d[MAX_N];
bool used[MAX_N];
vector<edge> G[MAX_N];
int INF = 10000000;
void dijkstra(int s)
{
    fill_n(d, MAX_N, INF);
    fill_n(used, MAX_N, false);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;

    q.push(P(0, s));
    while (!q.empty())
    {
        int dist, to;
        tie(dist, to) = q.top();
        q.pop();
        if (used[to])
            continue;
        used[to] = true;
        for (edge g : G[to])
        {
            if (d[g.to] > d[to] + g.dist)
            {
                d[g.to] = d[to] + g.dist;
                q.push(P(d[g.to], g.to));
            }
        }
    }
    return;
}

int main()
{
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, d, c;
        cin >> u >> v >> d >> c;

        u--;
        v--;

        edge e1 = {v, d, c};
        edge e2 = {u, d, c};

        G[u].push_back(e1);
        G[v].push_back(e2);
    }

    dijkstra(0);
    // コスト最小の経路を探して、コストの和の最小値を求める
    int min_total = 0;
    for (int v = 1; v < N; v++)
    {
        int min_cost = INF;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[v] == d[e.to] + e.dist && e.cost < min_cost)
                min_cost = e.cost;
        }
        min_total += min_cost;
    }
    cout << min_total << endl;

    return 0;
}