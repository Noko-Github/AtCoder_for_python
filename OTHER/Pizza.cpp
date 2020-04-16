#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MAX_STORE = 1000005;
const ll INF = 100000000000000;
vector<ll> stores(MAX_STORE, INF);
ll d;

int main()
{
    ll d;
    int n;
    int s;
    cin >> d >> n >> s;
    stores.push_back(0); // 本店を入力
    rep(i, n - 1)
    {
        ll distance;
        cin >> distance;
        stores.push_back(distance);
    }
    stores.push_back(d);

    sort(stores.begin(), stores.end());
    ll ans = 0;
    rep(i, s)
    {
        ll d2t;
        cin >> d2t;

        int ok, ng;
        ok = -1;
        ng = n;
        while (ok + 1 < ng)
        {
            ll mean = (ok + ng) / 2;
            // if (d2t == stores[mean])
            // {
            //     tot = 0;
            //     break;
            // }
            // ここに処理を書く
            if (stores[mean] < d2t)
            {
                ok = mean;
            }
            else
            {
                ng = mean;
            }
            // tot = min(tot, abs(d2t - stores[right]));
        }
        // cout << "tot is " << tot << endl;
        ans += min(abs(d2t - stores[ok]), abs(d2t - stores[ng]));
    }

    cout << ans << endl;
    return 0;
}