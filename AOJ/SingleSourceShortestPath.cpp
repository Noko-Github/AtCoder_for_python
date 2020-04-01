#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int max_V = 100010;
const ll INF = 1e+13;
vector<P> G[max_V];
ll dist[max_V];
bool seen[max_V];

void dijkstra(int r)
{
    priority_queue<P, vector<P>, greater<P>> que;
    dist[r] = 0;
    que.push(P(0, r));

    while (!que.empty())
    {
        int from, cost;
        tie(cost, from) = que.top();
        que.pop();
        seen[from] = true;

        for (P e : G[from])
        {
            int target, d;
            tie(target, d) = e;
            // すでに確定済みであれば無視
            if (seen[target])
                continue;
            // 更新する必要がなければ無視
            if (dist[target] < dist[from] + d)
                continue;

            dist[target] = dist[from] + d;
            que.push(P(dist[target], target));
        }
    }
}

int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++)
    {
        int from, to, d;
        cin >> from >> to >> d;
        G[from].push_back(P(to, d));
    }

    // dijkstra
    fill_n(dist, V, INF);
    fill_n(seen, V, false);
    dijkstra(r);

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {

            cout << dist[i] << endl;
        }
    }
    return 0;
}