#include <bits/stdc++.h>
using namespace std;

const int OTHERS = 0;
const int FRIEND = 1;
const int BLOCK = -1;

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0)
    {
        d = vector<int>(n, -1);
    }
    int find(int x)
    {
        if (d[x] < 0)
        {
            return x;
        }

        return d[x] = find(d[x]);
    }

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

    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};

int deg[100005];
vector<int> to[100005];
int main(void)
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
        uf.unite(a, b);
        deg[a]++;
        deg[b]++;
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
            {
                --ans;
            }
        }
        cout << ans << " ";
    }
    return 0;
}