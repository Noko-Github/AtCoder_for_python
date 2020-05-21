#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1000010;

int main()
{
    int n;
    cin >> n;

    vector<ll> table(MAX, 0);
    vector<ll> sum(MAX, 0);
    for (int i = 0; i < n; i++)
    {
        int A, B;
        cin >> A >> B;
        table[A]++;
        table[B + 1]--;
    }

    for (int i = 0; i < MAX; i++)
    {
        sum[i + 1] = sum[i] + table[i];
    }

    ll ans = 0;
    for (int i = 0; i < MAX; i++)
    {
        ans = max(ans, sum[i]);
    }

    cout << ans << endl;
    return 0;
}