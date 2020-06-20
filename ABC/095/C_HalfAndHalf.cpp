#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 100000000000;
    for (int k = 0; k <= 100000; k++)
    {
        ll X2 = max(X - k, ll(0));
        ll Y2 = max(Y - k, ll(0));
        ans = min(ans, X2 * A + Y2 * B + 2 * C * k);
    }

    cout << ans << endl;

    return 0;
}