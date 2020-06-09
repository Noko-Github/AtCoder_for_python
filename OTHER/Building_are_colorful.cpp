#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18;

int main()
{
    int N, K;
    cin >> N >> K;

    ll a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // 高くする数
    ll ans = INF;
    for (ll S = 0; S < (1 << N); S++)
    {
        ll inc = 0;
        ll max_h = 0;
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            // どの家を高くするか
            if (S & (1 << i))
            {
                // max_hよりも大きくする。
                if (max_h >= a[i])
                {
                    inc += (max_h - a[i]) + 1;
                    max_h++;
                }
                else
                {
                    max_h = a[i];
                }

                k++;
            }
            else
            {
                // 高くするビルに該当しない場合はそのままの高さを評価
                if (max_h < a[i])
                {
                    k++;
                    max_h = a[i];
                }
            }

            if (K == k)
            {
                break;
            }
        }
        if (K > k)
        {
            continue;
        }
        ans = min(ans, inc);
    }

    cout << ans << endl;
    return 0;
}