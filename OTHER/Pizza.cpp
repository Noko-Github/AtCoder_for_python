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

    sort(stores.begin(), stores.end());
    ll ans = 0;
    rep(i, s)
    {
        ll d2t;
        cin >> d2t;

        int left, right;
        left = 0;
        right = n - 1;
        int mean = 0;
        ll tot = INF;
        while (left <= right)
        {
            mean = (left + right) / 2;
            // ここに処理を書く
        }
    }

    cout << ans << endl;
    return 0;
}