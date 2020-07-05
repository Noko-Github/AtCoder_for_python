#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[300][300];
ll b[300][300];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }

    // ワーシャルフロイド法
    bool is_ng = false;
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    is_ng = true;
                }
                else if (i != j && j != k && k != i && a[i][j] == a[i][k] + a[k][j])
                {
                    b[i][j] = 1;
                }
            }
        }
    }
    if (is_ng)
    {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (b[i][j] == 0)
            {
                ans += a[i][j];
            }
        }
    }

    cout << ans / 2 << endl;
    return 0;
}