#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll fact[200020] = {0};
ll fact_inv[200020] = {0};
ll inv[200020] = {0};
void init_nCk(int n)
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

long long nCk(int n, int k)
{
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    long long ans = 1;
    for (int i = n; i >= n - k + 1; i--)
    {
        ans *= i;
        ans %= MOD;
    }
    return ans * fact_inv[k] % MOD;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    init_nCk(n);

    int ans = 0;
    int col = m;
    for (int x = n - 1; x >= 0; --x)
    {
        int now = col;
        if (x <= k)
        {
            now *= nCk(n - 1, x);
            now = now % MOD;
            ans += now;
            ans = ans % MOD;
        }
        col *= m - 1;
    }
    cout << ans % MOD << endl;
    return 0;
}