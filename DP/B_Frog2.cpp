#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18 + 100;

int main()
{
    int N, K;
    cin >> N >> K;

    int H[N];
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    ll dp[N + 200];
    fill_n(dp, N + 200, INF);

    dp[0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            if (i + k >= N)
                continue;
            dp[i + k] = min(dp[i + k], dp[i] + abs(H[i] - H[i + k]));
        }
    }

    cout << dp[N - 1] << endl;
    return 0;
}