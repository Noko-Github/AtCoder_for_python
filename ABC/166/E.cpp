#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;

    ll a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    map<ll, int> mp;
    for (int j = 0; j < N; j++)
    {
        int sa = j - a[j];
        int wa = a[j] + j;

        ans += mp[sa];
        mp[wa]++;
    }

    cout << ans << endl;
    return 0;
}