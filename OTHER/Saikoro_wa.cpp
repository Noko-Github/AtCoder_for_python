#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 100010;
double dp[MAX_K];

int main()
{
    int K;
    cin >> K;
    for (int i = K - 1; i >= 0; i--)
    {
        for (int k = 1; k <= 6; k++)
        {
            dp[i] += (dp[i + k] + 1.0) / 6.0;
        }
    }

    cout << dp[0] << endl;
    return 0;
}