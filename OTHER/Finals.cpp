#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a, b, cost;
    Edge(int a, int b, int cost) : a(a), b(b), cost(cost){};

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
            return x;

        return d[x] = find(d[x]);
    }

    // unite
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

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        edges.push_back(Edge(a, b, cost));
    }
    sort(edges.begin(), edges.end());

    UnionFind uf = UnionFind(n);
    stack<int> st;
    long long ans = 0;
    for (Edge edge : edges)
    {
        if (uf.unite(edge.a, edge.b))
        {
            ans += edge.cost;
            st.push(edge.cost);
        }
    }

    // 開催地分のコストを削除
    for (int i = 0; i < k - 1; i++)
    {
        int value = st.top();
        st.pop();
        ans -= value;
    }

    cout << ans << endl;
    return 0;
}

// input
/*
4 3 1
1 2 2 
2 3 9
2 4 5
*/

/*
5 6 2
1 2 5
1 3 3
2 3 4
2 5 7
3 4 6
4 5 5
*/