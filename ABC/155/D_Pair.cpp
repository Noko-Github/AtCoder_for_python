#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
const ll INF = ll(1e18) + 1;

int main(void)
{
    int N;
    ll K;
    cin >> N >> K;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());
    ll l = -INF;
    ll r = INF;
    while (l + 1 < r)
    {
        ll c = (l + r) / 2;
        bool ok = [&] {
            ll tot = 0;
            for (int i = 0; i < N; i++)
            {
                if (a[i] < 0)
                {
                    int left = -1;
                    int right = N;
                    while (left + 1 < right)
                    {
                        int middle = (left + right) / 2;
                        if (a[middle] * a[i] < c)
                            right = middle;
                        else
                            left = middle;
                    }
                    tot += N - right;
                }
                else
                {

                    int left = -1;
                    int right = N;
                    while (left + 1 < right)
                    {
                        int middle = (left + right) / 2;
                        if (a[i] * a[middle] < c)
                        {
                            left = middle;
                        }
                        else
                        {
                            right = middle;
                        }
                    }
                    tot += right;
                }
                if (a[i] * a[i] < c)
                    tot--;
            }

            tot /= 2;
            return tot < K;
        }();

        if (ok)
            l = c;
        else
            r = c;
    }

    cout << l << endl;

    return 0;
}