#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<long long> a;
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());

    ll INF = ll(1e+9) + 5;
    long long l = -INF;
    ll r = INF;

    while (l + 1 < r)
    {
        ll c = (l + r) / 2;
        bool ok = [&] {
            return false;
        }();

        if (ok)
            l = c;
        else
            r = c;
    }

    return 0;
}