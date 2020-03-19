#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> field;
vector<int> r_list;
vector<int> perm;
map<int, bool> used;

const int INF = 100000000;
int result = INF;

void dfs(int i, int n)
{
    if (i == n)
    {
        int tmp = 0;
        for (int j = 0; j < n - 1; j++)
        {
            tmp += field[perm[j]][perm[j + 1]];
        }
        result = min(result, tmp);
        return;
    }

    for (int j : r_list)
    {
        if (!used[j])
        {
            perm.push_back(j);
            used[j] = true;
            dfs(i + 1, n);
            perm.pop_back();
            used[j] = false;
        }
    }

    return;
}

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    field = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i < R; i++)
    {
        int r;
        cin >> r;
        r_list.push_back(r);
        used[r] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        field[A][B] = field[B][A] = C;
    }

    for (int i = 1; i <= N; i++)
    {
        field[i][i] = 0;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int j = 1; j <= N; j++)
        {

            for (int i = 1; i <= N; i++)
            {
                field[i][j] = min(field[i][j], field[i][k] + field[k][j]);
            }
        }
    }

    // This may be not necesarry.
    sort(r_list.begin(), r_list.end());

    // permutation
    for (int i : r_list)
    {
        perm.push_back(i);
        used[i] = true;
        dfs(1, r_list.size());
        perm.pop_back();
        used[i] = false;
    }

    cout << result << endl;

    return 0;
}