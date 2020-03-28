#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
using P = pair<int, ll>;

const int MAX_N = 1e+5;
int color[MAX_N]; // 0(黒), 1(白), -1(未訪問)
vector<P> G[MAX_N];

void dfs(int n, int tmp_col)
{
    // cout << "fill vector with :" << tmp_col << endl;
    color[n] = tmp_col;

    // 対象の頂点と繋がっている頂点を探索
    for (P e : G[n])
    {
        // cout << "target is " << e.first << endl;
        // cout << "target color is " << color[e.first] << endl;
        int t;
        ll cost;
        tie(t, cost) = e;
        // 既に着色済みならば、同色同士が隣接していないか判定
        if (color[t] != -1)
        {
            continue; // いつかは全てのノードが塗りつぶされるので無限ループはしない。
        }

        // 未探索の隣接した頂点があれば、現在の頂点とは異なる色で塗りつぶす
        // cout << "color[n] + cost % 2 is " << (color[n] + cost) % 2 << endl;
        dfs(t, (color[n] + cost) % 2);
    }
}

int main()
{
    int N;
    cin >> N;
    rep(i, N - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(P(v, w));
        G[v].push_back(P(u, w));
    }

    fill_n(color, N, -1);
    rep(i, N)
    {
        if (color[i] == -1)
        {
            dfs(i, 0);
        }
    }

    rep(i, N)
    {
        cout << color[i] << endl;
    }
    return 0;
}