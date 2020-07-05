#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100000;

int main()
{
    ll N, Q;
    vector<ll> A(MAX_N, 0);
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        ans += a;
        a--;
        A[a]++;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int b, c;
        cin >> b >> c;
        b--;
        c--;
        ll cnt = A[b];
        A[b] = 0;
        A[c] += cnt;
        ans = ans - ((b + 1) * cnt) + ((c + 1) * cnt);
        cout << ans << endl;
    }
    return 0;
}