#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18 + 100;

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int A;
    cin >> A;

    // DPと初期化
    ll dp[N + 10][A + 10];
    for (int i = 0; i < N + 10; i++)
    {
        for (int j = 0; j < A + 10; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= A; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i])
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
            }
        }
    }

    int ans = 10000000;
    for (int i = 0; i <= N; i++)
    {
        if (dp[i][A])
        {
            ans = min(ans, i);
        }
    }

    for (int i = 0; i <= N; i++)
    {
        cout << dp[i][A] << endl;
        if (dp[i][A] <= K)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}