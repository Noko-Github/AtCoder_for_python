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
};

int main()
{
    int n, q;
    cin >> n >> q;
    UnionFind uf = UnionFind(n);
    vector<bool> ans;
    for (int i = 0; i < q; i++)
    {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0)
        {
            uf.unite(x, y);
        }
        else
        {
            ans.push_back(uf.same(x, y));
        }
    }

    for (bool out : ans)
    {
        cout << out << endl;
    }
    return 0;
}