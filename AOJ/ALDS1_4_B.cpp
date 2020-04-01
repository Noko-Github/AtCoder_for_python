#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int N, Q;
    cin >> N;
    ll S[N];
    rep(i, N) cin >> S[i];

    cin >> Q;
    ll T[Q];
    rep(i, Q) cin >> T[i];

    int cnt = 0;
    for (ll t : T)
    {
        int left = 0;
        int right = N - 1;
        while (left <= right)
        {
            int mean = (left + right) / 2;
            if (t == S[mean])
            {
                cnt++;
                break;
            }
            if (t < S[mean])
            {
                right = mean - 1;
            }
            else
            {
                left = mean + 1;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}