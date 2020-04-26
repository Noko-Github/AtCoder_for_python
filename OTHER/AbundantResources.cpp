#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    ll A[N];
    ll B[N + 1];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    fill_n(B, N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        B[i + 1] = B[i] + A[i];
    }

    for (int i = 1; i <= N; i++)
    {
        ll ans = 0;
        for (int j = i; j <= N; j++)
        {
            ans = max(ans, B[j] - B[j - i]);
        }
        cout << ans << endl;
    }

    return 0;
}