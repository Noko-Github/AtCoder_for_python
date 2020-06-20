#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll N, M;
    cin >> N >> M;

    ll A[N];
    ll tot = 0;
    rep(i, N)
    {
        cin >> A[i];
        tot += A[i];
    }

    int ans = 0;
    rep(i, N)
    {
        if ((A[i] * 4 * M) >= tot)
        {
            ans++;
        }
    }

    if (ans >= M)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}