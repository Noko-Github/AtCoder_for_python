#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int A;
    cin >> A;

    // DPと初期化
    int dp[N + 10][A + 10];
    for (int i = 0; i < N + 10; i++)
    {
        for (int j = 0; j < A + 10; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= A; j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (j >= a[i])
            {
                dp[i + 1][j] += dp[i][j - a[i]];
            }
        }
    }

    cout << dp[N][A] << endl;

    return 0;
}