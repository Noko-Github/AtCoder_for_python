#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    bool have[N];
    fill_n(have, N, false);
    for (int i = 0; i < K; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int treat;
            cin >> treat;
            treat--;
            have[treat] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!have[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}