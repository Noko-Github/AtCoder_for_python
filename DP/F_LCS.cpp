#include <bits/stdc++.h>
using namespace std;

int dp[3010][3010] = {0};

int main()
{
    string s, t;
    cin >> s >> t;

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

    // 復元
    int i, j;
    i = s_len;
    j = t_len;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else
        {
            ans = s[i - 1] + ans;
            i--;
            j--;
        }
    }

    cout << ans << endl;
    return 0;
}