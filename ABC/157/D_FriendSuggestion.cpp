#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> d;
    UnionFind(int n) : d(n, -1) {}

    // find
    int find(int x)
    {
        if (d[x] < 0)
            return x;

        return d[x] = find(d[x]); // 更新（メモ化）
    }

    // union
    int unite(int x, int y)
    {
        // 根同士を連結する
        x = find(x);
        y = find(y);

        // 同じ連結成分であればfalse
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

    //size
    int size(int x)
    {
        return abs(d[find(x)]);
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int friends[n];
    fill_n(friends, n, 0);
    UnionFind uf = UnionFind(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        friends[a]++;
        friends[b]++;
        uf.unite(a, b);
    }

    vector<int> ng[n];
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ng[a].push_back(b);
        ng[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int ans = uf.size(i) - 1 - friends[i];
        for (int b : ng[i])
        {
            if (uf.same(i, b))
                ans--;
        }

        cout << ans << " ";
    }
    cout << endl;

    return 0;
}