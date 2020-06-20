#include <bits/stdc++.h>
using namespace std;

int N, M, Q;

vector<vector<int>> sum;
void buildSumTable(vector<int> L, vector<int> R)
{
    sum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++)
    {
        sum[L[i]][R[i]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
}

int getSumRange(int L, int R)
{
    return sum[R][R] - sum[L - 1][R] - sum[R][L - 1] + sum[L - 1][L - 1];
}

int main()
{
    cin >> N >> M >> Q;
    vector<int> L(M);
    vector<int> R(M);

    for (int i = 0; i < M; i++)
    {
        cin >> L[i] >> R[i];
    }

    vector<int> p(Q);
    vector<int> q(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> p[i] >> q[i];
    }
    buildSumTable(L, R);
    for (int i = 0; i < Q; i++)
    {
        cout << getSumRange(p[i], q[i]) << endl;
    }

    return 0;
}
