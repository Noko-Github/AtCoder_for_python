#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+6 + 10;

int main()
{

    int N;
    cin >> N;

    int flag[N][3];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // WRB
            flag[i][j] = 5;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        string S;
        cin >> S;
        int j = 0;
        for (char s : S)
        {
            if (s == 'W')
            {
                flag[j][0]--;
            }
            else if (s == 'R')
            {
                flag[j][1]--;
            }
            else if (s == 'B')
            {
                flag[j][2]--;
            }
            j++;
        }
    }

    // DPの定義と初期化
    int dp[N + 10][5];
    for (int i = 0; i < N + 9; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (dp[i][j] > 0 && j == k)
                {
                    continue;
                }
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + flag[i][k]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; i++)
    {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}