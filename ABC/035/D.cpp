#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+9;
const int MAX_V = 100000;
using P = pair<int, int>;
int V;
vector<P> G[MAX_V];
int d[MAX_V];

vector<P> G2[MAX_V];
int d2[MAX_V];
bool used[MAX_V];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> q;
    fill_n(d, V, INF);
    fill_n(used, V, false);
    d[s] = 0;
    q.push(P(0, s));

    while (!q.empty())
    {
        int v, t;
        tie(v, t) = q.top();
        q.pop();
        if (used[t])
            continue;
        used[t] = true;
        for (P e : G[t])
        {
            if (d[e.first] > d[t] + e.second)
            {
                d[e.first] = d[t] + e.second;
                q.push(P(d[e.first], e.first));
            }
        }
    }

    return;
}

void dijkstra2(int s)
{
    priority_queue<P, vector<P>, greater<P>> q;
    fill_n(d2, V, INF);
    d2[s] = 0;
    q.push(P(0, s));

    while (!q.empty())
    {
        int v, t;
        tie(v, t) = q.top();
        q.pop();
        if (d2[t] < v)
            continue;
        for (P e : G2[t])
        {
            if (d2[e.first] > d2[t] + e.second)
            {
                d2[e.first] = d2[t] + e.second;
                q.push(P(d2[e.first], e.first));
            }
        }
    }

    return;
}

int main()
{
    long long E, T;
    cin >> V >> E >> T;

    long long A[V];
    for (int i = 0; i < V; i++)
    {
        long long a;
        cin >> a;
        A[i] = a;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        P p = P(b, c);
        G[a].push_back(p);
        G2[b].push_back(P(a, c));
    }

    dijkstra(0);
    dijkstra2(0);
    long long result = 0;
    for (int i = 0; i < V; i++)
    {
        result = max(result, (T - d[i] - d2[i]) * A[i]);
    }

    cout << result << endl;
}