#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1000000;
// const int MOD = 1000000007;
const int MOD = 1e+9 + 7;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        fac[i] = i * fac[i - 1] % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    int W, H;
    cin >> W >> H;

    COMinit();
    cout << COM(W + H - 2, W - 1) << endl;
    return 0;
}