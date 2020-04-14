#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    bool friends[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            friends[i][j] = false;
            friends[j][i] = false;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        friends[x][y] = true;
        friends[y][x] = true;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        int t = bitset<32>(bit).count();
        if (t <= ans)
            continue;

        bool ok = true;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if ((bit >> i & bit >> j) & 1 && friends[i][j] == false)
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            ans = max(ans, t);
        }
    }

    cout << ans << endl;
    return 0;
}
