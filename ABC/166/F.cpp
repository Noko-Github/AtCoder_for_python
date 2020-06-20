#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3010;

int main()
{
    string s, t;
    cin >> s >> t;

    return 0;
    int dp[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; i++)
    {
        for (int j = 0; j < MAX_N; i++)
        {
            dp[i][j] = 0;
        }
    }

    int s_len = s.size();
    int t_len = t.size();
    for (int i = 0; i < s_len; i++)
    {
        for (int j = 0; j < t_len; j++)
        {
            if (s[i] == t[j])
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[s_len][t_len] << endl;
    return 0;
}