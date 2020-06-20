#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> H;
    vector<ll> S;

    for (int i = 0; i < N; i++)
    {
        ll h, s;
        cin >> h >> s;
        H.push_back(h);
        S.push_back(s);
    }

    ll ng = -1;
    ll ok = 10e15 * 2 + 10;
    while (ng + 1 < ok)
    {
        bool result = true;

        // 最大ペナルティ
        ll p = (ng + ok) / 2;

        // ペナルティにおいて、各風船が割れるか確認
        vector<ll> t;
        for (int n = 0; n < N; n++)
        {
            ll T = (p - H[n]) / S[n];
            //P >= H+S*t
            t.push_back((p - H[n]) / S[n]);
        }
        // ソートして昇順に
        sort(t.begin(), t.end());

        // 累積和？
        for (int n = 0; n < N; n++)
        {
            cout << t[n] << endl;
            if (t[n] < n)
            {
                result = false;
                break;
            }
            if (H[n] > p)
            {
                result = false;
                break;
            }
        }

        // 2分木更新
        if (result)
        {
            ok = p;
        }
        else
        {
            ng = p;
        }
    }

    cout << ok << endl;
    return 0;
}