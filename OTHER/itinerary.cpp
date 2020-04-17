#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18 + 10;
ll d[110][110];

void update(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = INF;
            d[j][i] = INF;
        }
    }
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 0;
    }

    vector<ll> ans;
    for (int i = 0; i < k; i++)
    {
        bool is_update;
        cin >> is_update;
        if (is_update)
        {
            int a, b;
            ll cost;
            cin >> a >> b >> cost;
            a--;
            b--;
            if (d[a][b] <= cost)
                continue;
            d[a][b] = cost;
            d[b][a] = cost;
            update(n);
        }
        else
        {
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            ans.push_back(d[from][to]);
        }
    }

    for (ll value : ans)
    {
        cout << (value == INF ? -1 : value) << endl;
    }
    return 0;
}