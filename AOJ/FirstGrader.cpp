#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[110][25];

int main()
{
    int N;
    cin >> N;

    vector<ll> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    dp[1][v[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (dp[i][j] > 0)
            {
                ll plus = j + v[i];
                ll minus = j - v[i];
                if (plus >= 0 && plus <= 20)
                    dp[i + 1][plus] += dp[i][j];
                if (minus >= 0 && minus <= 20)
                    dp[i + 1][minus] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][v[N - 1]] << endl;
    return 0;
}