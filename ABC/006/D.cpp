#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;

int dp[30000];

int b_search(int ng, int ok, int target)
{
    while (ng + 1 < ok)
    {
        int mid = (ng + ok) / 2;
        if (dp[mid] >= target)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    return ok;
}

int main()
{
    int n;
    cin >> n;

    // DPの初期化
    for (int i = 0; i < n; i++)
    {
        dp[i] = INF;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            dp[0] = a;
            continue;
        }

        if (dp[i - 1] < a)
        {
            dp[i] = a;
        }
        else
        {
            dp[b_search(-1, i - 1, a)] = a;
        }
    }

    int lis = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == INF)
            break;
        lis++;
    }

    cout << n - lis << endl;
    return 0;
}