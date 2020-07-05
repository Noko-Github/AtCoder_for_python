#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX_N = 5000;
const ll INF = 1e+18;
vector<P> taxi(MAX_N);
vector<int> G[MAX_N];
vector<P> short_G[MAX_N]; // 貼り直し用

void bfs(int start, int limit)
{
    ll dist[MAX_N];
    bool used[MAX_N];

    fill_n(dist, MAX_N, -1);
    fill_n(used, MAX_N, false);

    dist[start] = 0;
    used[start] = true;

    queue<int> que;
    que.push(start);

    while (!que.empty())
    {
        int from = que.front();
        que.pop();

        for (auto to : G[from])
        {
            // 探索済みは無視
            if (used[to])
                continue;

            if (dist[from] + 1 <= limit)
            {
                used[to] = true;
                short_G[start].push_back(P(taxi[start].first, to)); // 辺を貼り直す
                dist[to] = dist[from] + 1;                          // 距離をインクリメント
                que.push(to);
            }
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int cost, dist;
        cin >> cost >> dist;
        taxi[i] = P(cost, dist);
    }

    for (int i = 0; i < K; i++)
    {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    // 各街の移動距離と移動可能点を計算してグラフを貼り直す
    for (int i = 0; i < N; i++)
    {
        // bfsでたどり着ける距離 <= 移動可能距離であれば辺を貼り直す
        bfs(i, taxi[i].second);
    }

    for (int from = 0; from < N; from++)
    {
        for (auto p : short_G[from])
        {
            int cost, to;
            tie(cost, to) = p;
        }
    }

    // ダイクストラ法で最短コストを求める
    ll dist[N];
    fill_n(dist, N, INF);
    auto dijkstra = [&]() {
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0, 0));
        dist[0] = 0;

        while (!que.empty())
        {
            P p = que.top();
            que.pop();

            ll cost, from;
            tie(cost, from) = p;

            for (auto sg : short_G[from])
            {
                ll c, t;
                tie(c, t) = sg;

                if (dist[t] > dist[from] + c)
                {
                    dist[t] = dist[from] + c;
                    que.push(P(dist[t], t));
                }
            }
        }
    };
    dijkstra();
    cout << dist[N - 1] << endl;
    return 0;
}