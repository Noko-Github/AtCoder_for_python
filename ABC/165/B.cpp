#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    cin >> x;

    ll ans = 0, a = 100;
    while (a < x)
    {
        a += a / 100;
        ans++;
    }

    cout << ans << endl;
}