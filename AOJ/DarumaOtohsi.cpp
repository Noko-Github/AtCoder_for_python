#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 330;
ll dp[MAX_N][MAX_N];
vector<ll> w(MAX_N, 0);

int n;

ll rec(int l, int r)
{
    ll res = 0;
    // 既に計算したことがある場合
    if (dp[l][r] != -1)
        return dp[l][r];

    // 間に何もない場合(rは開区間なので)
    if (abs(l - r) <= 1)
    {
        return 0;
    }

    if (abs(w[l] - w[r - 1]) <= 1 && rec(l + 1, r - 1) == r - l - 2)
    {
        res = r - l;
    }

    for (int mid = l + 1; mid <= r - 1; ++mid)
    {
        res = max(res, rec(l, mid) + rec(mid, r));
    }

    return dp[l][r] = res;
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << rec(0, n) << endl;
    }

    return 0;
}