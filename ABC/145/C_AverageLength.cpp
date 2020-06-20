#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
bool used[8];
int perm[8];
vector<P> A;
double tot = 0;

void dfs(int current, int limit)
{
    if (current == limit)
    {
        // 距離の合計を追加
        for (int i = 0; i < limit - 1; i++)
        {
            double x, y, nx, ny;
            tie(x, y) = A[perm[i]];
            tie(nx, ny) = A[perm[i + 1]];
            tot += sqrt((nx - x) * (nx - x) + (ny - y) * (ny - y));
        }
        return;
    }

    for (int i = 0; i < limit; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            perm[current] = i;
            dfs(current + 1, limit);
            used[i] = false;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        A.push_back(P(x, y));
    }

    for (int i = 0; i < N; i++)
    {
        used[i] = true;
        perm[0] = i;
        dfs(1, N);
        used[i] = false;
    }

    double div = 1;
    for (int i = N; i > 0; i--)
    {
        div *= i;
    }

    double ans = tot / div;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}