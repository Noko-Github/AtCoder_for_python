#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int D, N;
    cin >> D >> N;

    vector<int> T(D);
    for (int i = 0; i < D; i++)
    {
        cin >> T[i];
    }

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<vector<int>> dp(D, vector<int>(N, -1));
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (T[i] < A[j] || B[j] < T[i])
                continue;

            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                for (int k = 0; k < N; k++)
                {
                    if (dp[i - 1][k] >= 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(C[j] - C[k]));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp[D - 1][i]);
    }

    cout << ans << endl;

    return 0;
}