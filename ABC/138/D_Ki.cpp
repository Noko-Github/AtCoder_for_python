#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 10000000;
vector<ll> G[MAX_N];
bool seen[MAX_N];
vector<int> ans;

void dfs(int v, int p = -1)
{
    for (int g : G[v])
    {
        if (g == p)
            continue;
        ans[g] += ans[v];
        dfs(g, v);
    }
    return;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ans.resize(N);
    for (int i = 0; i < Q; i++)
    {
        ll root, cost;
        cin >> root >> cost;
        root--;
        ans[root] += cost;
    }

    dfs(0);
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
