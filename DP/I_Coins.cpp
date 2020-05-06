#include <bits/stdc++.h>
using namespace std;

double dp[3010][3010];
int main()
{

    int N;

    cin >> N;
    double p[N];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double res = 0.0;
    for (int j = N / 2 + 1; j <= N; j++)
    {
        res += dp[N][j];
    }
    cout << fixed << setprecision(10) << res << endl;

    return 0;
}