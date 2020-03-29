#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

vector<vector<long long>> A(MAX_N, vector<long long>(MAX_M, 0));

int main()
{
    int N, M;
    cin >> N >> M;

    A.resize(N);
    rep(i, N)
    {
        rep(j, M) cin >> A[i][j];
    }

    long long ans = 0;
    for (int t1 = 0; t1 < M; t1++)
    {
        for (int t2 = t1 + 1; t2 < M; t2++)
        {
            long long tot = 0;
            for (int i = 0; i < N; i++)
            {
                tot += max(A[i][t1], A[i][t2]);
            }
            ans = max(ans, tot);
        }
    }

    cout << ans << endl;
    return 0;
}