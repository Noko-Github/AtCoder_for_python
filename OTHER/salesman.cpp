#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int N;
int dist[21][21];

int dp[(1 << 20) + 1][21];
int rec(int bit, int v)
{
    // すでに探索済み出会ったらreturn
    if (dp[bit][v] != -1)
        return dp[bit][v];

    // 初期値
    if (bit == (1 << v))
    {
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    int res = INF;
    // bitのvを除いたもの
    int prev_bit = bit & ~(1 << v);

    // v の手前のノードとしてuを全探索
    for (int u = 0; u < N; u++)
    {
        if (!(prev_bit & (1 << u)))
            continue;
        if (res > rec(prev_bit, u) + dist[u][v])
        {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> dist[i][j];
        }
    }

    // テーブルを全て-1にしておく
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        for (int v = 0; v < N; v++)
        {
            dp[bit][v] = -1;
        }
    }

    int res = INF;
    for (int v = 0; v < N; v++)
    {
    }
    return 0;
}