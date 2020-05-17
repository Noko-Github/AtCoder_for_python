#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 510000;
ll frag[MAX];
ll inv[MAX];
ll fraginv[MAX];
const ll MOD = 1000000007;

void init(int n)
{
    frag[0] = frag[1] = 1;
    fraginv[0] = fraginv[1] = 1;
    inv[1] = 1;

    for (ll i = 2; i < n; i++)
    {
        frag[i] = frag[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fraginv[i] = fraginv[i - 1] * inv[i] % MOD;
    }
}

ll nCk(int n, int k)
{
    return frag[n] * (fraginv[k] * fraginv[n - k] % MOD) % MOD;
}

int main()
{
    int N, K;
    cin >> N >> K;
    init(N + K);
    cout << nCk(N + K - 1, K) % MOD << endl;
    return 0;
}