#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

ll comb(ll n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;

    int cnt[n];
    fill_n(cnt, n, 0);
    rep(i, n) cnt[a[i]]++;
    ll tot = 0;
    rep(i, n) tot += comb(cnt[i]);

    rep(i, n)
    {
        ll ans = tot;
        ans -= comb(cnt[a[i]]);
        ans += comb(cnt[a[i]] - 1);
        cout << ans << endl;
    }

    return 0;
}