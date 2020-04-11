#include <bits/stdc++.h>
using namespace std;

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

    // unite
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;

        if (x > y)
            swap(x, y);

        d[x] += d[y];
        d[y] = x;

        return true;
    }

    // same
    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }

    // size
    int size(int x)
    {
        return -d[find(x)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    int a_list[m], b_list[m];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a_list[i] = a;
        b_list[i] = b;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        UnionFind uf = UnionFind(n);
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                continue;
            uf.unite(a_list[j], b_list[j]);
        }
        if (uf.size(0) != n)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}