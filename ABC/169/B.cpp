#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> A;

ll const limit = 1e18;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        A.push_back(a);
    }

    ll ans = 1;
    for (ll a : A)
    {
        if (limit / ans >= a)
        {
            ans *= a;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}