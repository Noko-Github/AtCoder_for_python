#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
vector<P> distance;

int main()
{
    ll K, N;
    cin >> K >> N;
    vector<ll> A(N, 0);
    rep(i, N)
    {
        cin >> A[i];
    }

    ll max_distance = A[0];
    int start = 0;
    rep(i, N - 1)
    {
        if (max_distance < A[i + 1] - A[i])
        {
            max_distance = A[i + 1] - A[i];
            start = i + 1;
        }
    }
    if (max_distance < K - A[N - 1])
    {
        max_distance = K - A[N - 1];
        start = -1;
    }

    // start以外ー>全体引く最大
    ll ans = 0;
    // cout << start << endl;
    // cout << max_distance << endl;
    // 最大がA[0](start = 0)
    if (start == 0)
    {
        ans = K - A[0] - (K - A[N - 1]);
    }
    // 最大がA[N-1](start = -1)
    else if (start == -1)
    {
        ans = K - max_distance - A[0];
    }
    // 最大が途中(else)
    else
    {
        ans = K - max_distance;
    }

    if (max_distance < A[0] + (K - A[N - 1]))
    {
        ans = K - A[0] - (K - A[N - 1]);
    }

    cout << ans << endl;
    return 0;
}