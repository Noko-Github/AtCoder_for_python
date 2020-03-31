#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    vector<P> A[N];
    for (int i = 0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            A[i].push_back(P(x, y));
        }
    }

    // bit全探索
    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        int honest = 0;
        int ok = true;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                // cout << "bitは" << bit << " iは" << i << " シフトは" << (1 << i) << endl;
                for (P o : A[i])
                {
                    int x, y;
                    tie(x, y) = o;
                    // cout << "x, y =" << x << " " << y << "シフト=" << (bit & (1 << x)) << endl;
                    // if ((bit & (1 << x)) != y)
                    if (((bit >> x) & 1) != y)
                    {
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    break;
                // cout << "find honest: bit=" << bit << "i=" << i << endl;
                honest++;
            }
        }
        if (ok)
        {
            // cout << "all ok bit=" << bit << " honest = " << honest << endl;
            ans = max(ans, honest);
        }
    }

    cout << ans << endl;
    return 0;
}