#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;
void add(int &a, int b)
{
    a = (a + b) % MOD;
}

void mul(int &a, int b)
{
    a = a * b % MOD;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> F(N, -1);
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        F[a - 1] = b - 1;
    }

    int dp[101][3][3];

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 3; b++)
            {

                // cs: i日目のパスタの候補
                vector<int> cs = {0,
                                  1,
                                  2};
                if (F[i] >= 0)
                    cs = {F[i]};

                for (int c : cs)
                {
                    // 「3日連続ならける]
                    if (i >= 2 && a == b && b == c)
                        continue;
                    add(dp[i + 1][b][c], dp[i][a][b]);
                }
            }
        }
    }
    int ans = 0;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            add(ans, dp[N][a][b]);
        }
    }

    cout << ans << endl;
    return 0;
}