#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int R, C;
    cin >> R >> C;

    bool origin_field[R][C];
    bool field[R][C];
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> origin_field[r][c];
        }
    }

    ll ans = 0;
    for (int S = 0; S < (1 << R); S++)
    {
        memcpy(field, origin_field, sizeof(origin_field));
        for (int r = 0; r < R; r++)
        {
            if ((S & (1 << r)) == 0)
                continue;
            for (int c = 0; c < C; c++)
            {
                // 排他的論理和XORで反転
                field[r][c] = !field[r][c];
            }
        }

        // 計算
        ll tmp = 0;
        for (int c = 0; c < C; c++)
        {
            ll count = 0;
            for (int r = 0; r < R; r++)
            {
                // 数が多い方1 or 0を選択
                if (field[r][c] == 0)
                {
                    count++;
                }
            }
            tmp += ((R - count) <= R / 2) ? count : R - count;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}