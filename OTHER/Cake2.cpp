#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2100][2100];
int b[2100];
int a;

ll calc(int l, int r, int s)
{
    cout << "(l, r, s)=(" << l << " " << r << " " << s << ")" << endl;
    if (dp[l][r] != -1)
        return dp[l][r];

    if (l == r)
    {
        if (s)
            return dp[l][r] = 0;
        return dp[l][r] = b[l];
    }
    if (s)
    {
        if (b[l] > b[r])
        {
            return dp[l][r] = calc((l + 1) % a, r, 0);
        }
        else
        {
            return dp[l][r] = calc(l, (r + a - 1) % a, 0);
        }
    }

    return dp[l][r] = max(calc((l + 1) % a, r, 1) + b[l], calc(l, (r + a - 1) % a, 1) + b[r]);
}

int main()
{

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < 2100; i++)
    {
        for (int j = 0; j < 2100; j++)
        {
            dp[i][j] = -1;
        }
    }

    ll ret = 0;
    for (int i = 0; i < a; i++)
    {
        ret = max(ret, calc((i + 1) % a, (i + a - 1) % a, 1) + b[i]);
        return 0;
    }
    cout << ret << endl;
    return 0;
}