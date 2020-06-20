#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> lights[M];
    vector<int> on;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int s = 0;
            cin >> s;
            s--;
            lights[i].push_back(s);
        }
    }

    for (int i = 0; i < M; i++)
    {
        int p = 0;
        cin >> p;
        on.push_back(p);
    }

    int ans = 0;
    for (long long bit = 0; bit < (1 << N); bit++)
    {
        // それぞれの電球がONになるか確認
        bool ok = true;
        for (int i = 0; i < M; i++)
        {
            int turned_sum = 0;
            for (int light : lights[i])
            {
                if (bit & (1 << light))
                {
                    turned_sum++;
                }
            }
            if (turned_sum % 2 != on[i])
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;
        ans++;
    }

    cout << ans << endl;
}