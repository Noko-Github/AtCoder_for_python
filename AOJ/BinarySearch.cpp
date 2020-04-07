#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{

    int N;
    cin >> N;
    vector<ll> S;
    rep(i, N)
    {
        ll s;
        cin >> s;
        S.push_back(s);
    }
    sort(S.begin(), S.end());

    int q;
    cin >> q;
    vector<ll> T;
    rep(i, q)
    {
        ll t;
        cin >> t;
        T.push_back(t);
    }

    int ans = 0;
    for (ll t : T)
    {
        ll ng = -1;
        ll ok = N;
        while (abs(ng - ok) > 1)
        {
            ll mid = (ng + ok) / 2;
            if (S[mid] < t)
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }

        if (t == S[ok])
            ans++;
    }
    cout << ans << endl;

    return 0;
}