#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll modpow(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n = n >> 1;
    }
    return res;
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    ll A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll dist[N];
    dist[0] = 0;
    for (int i = 1; i < N; i++)
    {
        dist[i] = (dist[i - 1] + modpow(A[i - 1], A[i]));
    }

    ll ans = 0;
    ll from = 0;
    for (int i = 0; i < Q; i++)
    {
        int to;
        cin >> to;
        to--;
        ans += abs(dist[to] - dist[from]) % mod;
        from = to;
    }
    ans += abs(dist[from] - dist[0]);
    ans %= mod;

    cout << ans << endl;

    return 0;
}