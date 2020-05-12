#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18 + 10;
const int D = 60;
const int MAX_N = 2000005;
int to[D][MAX_N];

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> to[0][i];
        to[0][i]--;
    }

    for (int i = 0; i < D - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            to[i + 1][j] = to[i][to[i][j]];
        }
    }

    int v = 0;
    for (int i = D - 1; i >= 0; i--)
    {
        ll l = 1ll << i;
        if (l <= k)
        {
            v = to[i][v];
            k -= l;
        }
    }

    cout << v + 1 << endl;

    return 0;
}