#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, ll>;
vector<P> G[100100];

int main()
{
    ll N, M;
    cin >> N >> M;
    ll H[N];
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(P(b, H[b]));
        G[b].push_back(P(a, H[a]));
    }
    bool seen[N];
    fill_n(seen, N, false);
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!seen[i])
        {
            bool is_count = true;
            for (P g : G[i])
            {
                int to;
                ll height;
                tie(to, height) = g;
                if (height < H[i])
                {
                    seen[to] = true;
                }
                else
                {
                    is_count = false;
                    break;
                }
            }
            if (is_count)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}