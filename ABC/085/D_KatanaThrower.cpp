#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, H;
    cin >> N >> H;

    vector<int> a = vector<int>(N);
    vector<int> b = vector<int>(N);

    int max_a = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
        max_a = max(max_a, a[i]);
    }

    sort(b.rbegin(), b.rend());

    int min_cnt = H;
    for (int k = 0; k <= N; k++)
    {
        int cnt = 0;
        if (k > 0)
        {
            H = H - b[k - 1];
            cnt += k;
        }

        if (H > 0)
        {
            cnt = cnt + (H + max_a - 1) / max_a;
        }

        min_cnt = min(min_cnt, cnt);
    }

    cout << min_cnt;

    return 0;
}