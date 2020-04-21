#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 100000;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll A[n];
    ll act[n];
    fill_n(A, n, 0);
    A[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll dist;
        cin >> dist;
        A[i + 1] = dist + A[i];
    }

    ll where = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ll move;
        cin >> move;
        ans += abs(A[move + where] - A[where]);
        ans = ans % mod;
        where += move;
    }

    cout << ans << endl;
    return 0;
}