#include <bits/stdc++.h>
using namespace std;

// 二項係数を計算するライブラリ
const long long MAX = 10000000;
const long long MOD = 1e+9 + 7;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (long long i = 2; i < MAX; i++)
    {
        if (i < 100)
        {

            cout << "MOD%" << i << "=" << MOD % i << endl;
        }
        fac[i] = i * fac[i - 1] % MOD;
        inv[i] = -inv[MOD % i] * (MOD / i) % MOD; // MOD%iの値きになる
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long solve(long long X, long long Y)
{
    if ((X + Y) % 3 != 0)
    {
        return 0;
    }

    long long n = (-X + Y * 2) / 3;
    long long m = (-Y + X * 2) / 3;

    return COM(n + m, n);
}

int main()
{
    COMinit();
    long long X, Y;
    cin >> X >> Y;

    cout << solve(X, Y) << endl;

    return 0;
}