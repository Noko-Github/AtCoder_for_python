#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int MAX_N = 101;
int tot = 0;

void dfs(int i, int N, int X, int cnt, int mount)
{
    if (cnt == 3)
    {
        if (mount == X)
        {
            tot++;
        }
        return;
    }

    for (int j = i + 1; j <= N; j++)
    {
        dfs(j, N, X, cnt + 1, mount + j);
    }
}

int main()
{
    int N, X;
    cin >> N >> X;

    for (int i = 1; i <= N; i++)
    {
        dfs(i, N, X, 1, i);
    }

    cout << tot << endl;
}
