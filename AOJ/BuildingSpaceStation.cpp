#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a, b;
    double cost;

    Edge(int a, int b, double cost) : a(a), b(b), cost(cost){};
    bool operator<(const Edge &right) const { return cost < right.cost; }
};

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0) : d(n, -1){};

    int find(int x)
    {
        if (d[x] < 0)
            return x;

        return d[x] = find(d[x]);
    }

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
};

struct Cell
{
    double x, y, z, r;
    Cell(double x, double y, double z, double r) : x(x), y(y), z(z), r(r){};
};

double calc(Cell a, Cell b)
{
    double xx = (a.x - b.x) * (a.x - b.x);
    double yy = (a.y - b.y) * (a.y - b.y);
    double zz = (a.z - b.z) * (a.z - b.z);
    double dist = sqrt(xx + zz + yy) - a.r - b.r;
    if (dist < 0.0)
        dist = 0.0;
    return dist;
}

vector<Edge> edges;
int main()
{
    while (1)
    {
        int N;
        cin >> N;
        if (N == 0)
            return 0;
        vector<Cell> cells;

        for (int i = 0; i < N; i++)
        {
            double x, y, z, r;
            cin >> x >> y >> z >> r;
            cells.push_back(Cell(x, y, z, r));
        }

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                edges.push_back(Edge(i, j, calc(cells[i], cells[j])));
            }
        }
        sort(edges.begin(), edges.end());

        double ans = 0;
        UnionFind uf = UnionFind(N);
        for (Edge edge : edges)
        {
            if (uf.unite(edge.a, edge.b))
            {
                ans += edge.cost;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
