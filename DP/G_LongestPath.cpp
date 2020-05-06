#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
int dp[100100];

int rec(int v)
{
    if (dp[v] != -1)
    {
        return dp[v];
    }

    int res = 0;
    for (auto nv : G[v])
    {
        res = max(res, rec(nv) + 1);
    }

    return dp[v] = res;
}

int main()
{
    // 入力受け取り
    cin >> N >> M;
    G.assign(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
    }

    // 初期化
    for (int v = 0; v < N; v++)
    {
        dp[v] = -1;
    }

    // 全ノードを一通り更新しながら答えを求める
    int res = 0;
    for (int v = 0; v < N; v++)
    {
        res = max(res, rec(v));
    }

    cout << res << endl;
    return 0;
}