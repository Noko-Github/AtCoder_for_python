#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> perm;
const int INF = 100000000;

int main()
{
    int N, M;
    cin >> N >> M;
    perm = vector<vector<int>>(N, vector<int>(N, INF));

    for (int i = 0; i < M; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        perm[a][b] = perm[b][a] = min(perm[a][b], t);
    }

    for (int i = 0; i < N; i++)
    {
        perm[i][i] = 0;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                perm[i][j] = min(perm[i][j], perm[i][k] + perm[k][j]);
            }
        }
    }

    int max_t = INF;
    for (int i = 0; i < N; i++)
    {
        int tmp_t = 0;
        for (int j = 0; j < N; j++)
        {
            tmp_t = max(tmp_t, perm[i][j]);
        }
        max_t = min(tmp_t, max_t);
    }

    cout << max_t << endl;
    return 0;
}