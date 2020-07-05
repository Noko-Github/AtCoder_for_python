#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18;
const ll MAX_N = 10000001;
ll A[MAX_N] = {INF};

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;
    for (int k = 1; k <= N; k++)
    {
        for (int i = k; i <= N; i += k)
        {
            A[i]++;
        }

        ans += k * A[k];
    }

    cout << ans << endl;
    return 0;
}