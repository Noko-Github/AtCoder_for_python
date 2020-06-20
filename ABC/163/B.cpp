#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    int A[M];

    ll ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        ans += A[i];
    }

    int bad = -1;
    cout << ((N - ans >= 0) ? (N - ans) : bad) << endl;
    return 0;
}