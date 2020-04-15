#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
    int a, b;
    ll cost;
    Edge(int a, int b, ll cost) : a(a), b(b), cost(cost){};
    bool operator<(const Edge &right) const
    {
        return cost < right.cost;
    }
};

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0) : d(n, -1){};

    // find
    int find(int x)
    {
        if (d[x] < 0)
        {
            return x;
        }

        return d[x] = find(d[x]);
    }

    //unite
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (d[x] > d[y])
        {
            swap(x, y);
        }

        d[x] += d[y];
        d[y] = x;

        return true;
    }

    // same
    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }
};

vector<Edge> edges;
int main()
{
    int V, E;
    cin >> V >> E;

    ll tot = 0;

    UnionFind uf = UnionFind(V);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        ll cost;
        cin >> a >> b >> cost;
        edges.push_back(Edge(a, b, cost));
    }
    sort(edges.begin(), edges.end());

    for (Edge edge : edges)
    {
        if (uf.unite(edge.a, edge.b))
        {
            tot += edge.cost;
        }
    }

    cout << tot << endl;
    return 0;
}