#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll ans = 0;
    ll x = 0;
    cin >> x;
    ans += (x / 500) * 1000;
    x = x % 500;
    if (x != 0)
    {
        ans += (x / 5) * 5;
    }

    cout << ans << endl;
    return 0;
}