#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> A;
    vector<ll> B;

    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    // ソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans;
    if (N % 2 == 0)
    {
        // 偶数
        ll ma = A[N / 2] + A[N / 2 - 1];
        ll mb = B[N / 2] + B[N / 2 - 1];
        ans = mb - ma + 1;
    }
    else
    {
        // 奇数
        ll ma = A[N / 2];
        ll mb = B[N / 2];
        ans = mb - ma + 1;
    }

    cout << ans << endl;
    return 0;
}