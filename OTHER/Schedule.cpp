#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    //2->J, 1->O, 0->I
    int mandatory[n];
    for (int i = 0; i < n; i++)
    {
        char member_name;
        cin >> member_name;
        switch (member_name)
        {
        case 'J':
            mandatory[i] = 2;
            break;
        case 'O':
            mandatory[i] = 1;
            break;
        case 'I':
            mandatory[i] = 0;
            break;
        }
    }

    // DPの宣言と初期化
    ll dp[n][1 << 3];
    for (int i = 0; i < n; i++)
    {
        for (int S = 0; S < (1 << 3); S++)
        {
            dp[i][S] = 0;
        }
    }
    // 初日はJ君とmandatory[0]がいればOK
    for (int S = 0; S < (1 << 3); S++)
    {
        if (S & (1 << mandatory[0]) && S & (1 << 2))
        {
            dp[0][S] = 1;
        }
    }

    // 2日目以降を計算
    for (int i = 0; i < n - 1; i++)
    {
        // 2日目以降の条件は以下
        // ①前日のmemberが参加しているand 当日にも参加している。or ②前日に当日のmandatoryが出席している&当日のmandataroy。
        for (int S = 0; S < (1 << 3); S++)
        {
            // if (!dp[i][S])
            // 該当なし。
            // continue;
            for (int n_S = 0; n_S < (1 << 3); n_S++)
            {
                // パターン①
                // if ((n_S & (1 << mandatory[i])) && (n_S & (1 << mandatory[i + 1])))
                // {
                //     dp[i + 1][n_S] += dp[i][S];
                // }
                // パターン②
                if (S & (1 << mandatory[i + 1]))
                {
                    if ((S & (1 << mandatory[i + 1])) && (n_S & (1 << mandatory[i + 1])))
                    {
                        dp[i + 1][n_S] += dp[i][S];
                        dp[i + 1][n_S] %= 10007;
                    }
                }
                else
                {
                    // パターン①
                    if ((n_S & S) && (n_S & (1 << mandatory[i + 1])))
                    {
                        dp[i + 1][n_S] += dp[i][S];
                        dp[i + 1][n_S] %= 10007;
                    }
                }
            }
        }
        //確認
        // for (int S = 0; S < (1 << 3); S++)
        // {
        //     cout << bitset<3>(S) << endl;
        //     cout << dp[1][S] << endl;
        // }
    }
    // 確認
    // for (int S = 0; S < (1 << 3); S++)
    // {
    //     cout << bitset<3>(S) << endl;
    //     cout << dp[0][S] << endl;
    // }

    // 答えを算出
    ll ans = 0;
    for (int S = 0; S < (1 << 3); S++)
    {
        ans += dp[n - 1][S];
        ans %= 10007;
    }

    cout << ans << endl;
    return 0;
}