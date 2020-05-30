#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q > 0)
    {
        int dp[1010][1010] = {0};

        string X, Y;
        cin >> X >> Y;

        for (int i = 0; i <= X.size(); i++)
        {
            for (int j = 0; j <= Y.size(); j++)
            {
                if (X[i] == Y[j])
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j] + 1);
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        }

        cout << dp[X.size()][Y.size()] << endl;
        q--;
    }
    return 0;
}
