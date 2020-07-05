#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N, 0);
    vector<ll> B(M, 0);
    vector<ll> A_acc(N + 1, 0);
    vector<ll> B_acc(M + 1, 0);
    A_acc[0] = 0;
    B_acc[0] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A_acc[i + 1] = A_acc[i] + A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
        B_acc[i + 1] = B_acc[i] + B[i];
    }

    cout << endl;
    // 決め打ち＋累積和＋２分探索
    ll ans = 0;
    for (int i = 0; i < N + 1; i++)
    {
        ll rem = K - A_acc[i];
        if (rem < 0)
            continue;
        ll cnt = upper_bound(B_acc.begin(), B_acc.end(), rem) - B_acc.begin();
        cnt--;
        ans = max(ans, cnt + i);
    }

    cout << ans << endl;
    return 0;
}