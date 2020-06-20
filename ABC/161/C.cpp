#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;

    return gcd(y, x % y);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    // cout << gcd(N, K) << endl;

    ll tmp = N % K;
    cout << min(tmp, abs(tmp - K)) << endl;
    return 0;
}