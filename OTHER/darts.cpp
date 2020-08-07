#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<ll> P;
    vector<ll> T_P;
    P.push_back(0);
    for (int i = 0; i < N; i++)
    {
        ll value;
        cin >> value;
        P.push_back(value);
    }
    sort(P.begin(), P.end());

    for (int i = 0; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            T_P.push_back(P[i] + P[j]);
        }
    }

    sort(T_P.begin(), T_P.end());

    ll ans = 0;
    for (ll t_p : T_P)
    {
        if (t_p > M)
        {
            continue;
        }
        ans = max(ans, t_p + *(upper_bound(T_P.begin(), T_P.end(), M - t_p) - 1));
    }

    cout << ans << endl;
    return 0;
}