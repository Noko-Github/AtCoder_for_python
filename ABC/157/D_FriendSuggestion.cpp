#include <bits/stdc++.h> // サイズはマイナスなので慎重に
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0) : d(n, -1) {} // すべて根でサイズは1
    int find(int x)
    {
        if (d[x] < 0)
            return x;
        d[x] = find(d[x]); // メモ化
        return d[x];
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y); // 根同士を連結する
        if (x == y)
            return false; // 同じ根なら何もしない
        if (d[x] > d[y])  // サイズはマイナスなので慎重に
            swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y)
    {
        if (find(x) == find(y))
            return true;
        return false;
    }

    int size(int x)
    {
        return -d[find(x)];
    }
};

int deg[1000005];
vector<int> to[1000005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        deg[a]++;
        deg[b]++;
        uf.unite(a, b);
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int ans = uf.size(i) - 1 - deg[i];
        for (int u : to[i])
        {
            if (uf.same(i, u))
                --ans;
        }
        printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}