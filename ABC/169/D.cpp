#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    // 素因数分解
    ll limit = n;
    map<ll, int> mp;
    for (ll i = 2; i * i < n; i++)
    {
        ll x = 0;
        // 割り切れるなら
        while (n % i == 0)
        {
            n /= i;
            x++;
        }
        mp[i] = x;
    }
    if (n != 1)
    {
        mp[n]++;
    }

    int ans = 0;
    for (auto myPair : mp)
    {
        int count = myPair.second;
        int iter = 1;
        while (count >= iter)
        {
            count -= iter;
            iter++;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}