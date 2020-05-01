#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18 + 10;

int main()
{
    int N, M;
    cin >> N >> M;

    int D[N];
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    int C[M];
    for (int i = 0; i < M; i++)
    {
        cin >> C[i];
    }

    ll dp[N + 10][M + 10];
    for (int i = 0; i < N + 9; i++)
    {
        for (int j = 0; j < M + 9; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = i; j <= M; j++)
        {
            dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j] + D[i] * C[j]);
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}