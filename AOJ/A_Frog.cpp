#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long dp[N + 10];
    long long height[N];

    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }

    fill_n(dp, N + 10, 1e+18 + 10);

    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(height[i] - height[i + 1]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(height[i] - height[i + 2]));
    }

    cout << dp[N - 1] << endl;
    return 0;
}