#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18 + 10;

int N, M, X;
int cost[12];
int skills[12];
int point[12][12];
bool used[12];
ll ans = INF;

bool is_achieve_skills()
{
    for (int i = 0; i < M; i++)
    {
        if (skills[i] < X)
        {
            return false;
        }
    }

    return true;
}

void dfs(int i, ll sum_money)
{
    if (is_achieve_skills())
    {
        // 全てのスキルを達成
        ans = min(ans, sum_money);
        return;
    }

    // cout << "--------------------------" << endl;
    // cout << i << endl;
    // cout << sum_money << endl;
    // for (int j = 0; j < M; j++)
    // {
    //     cout << skills[j] << endl;
    // }
    // cout << "--------------------------" << endl;

    // 残りの本を購入
    for (int j = i + 1; j < N; j++)
    {
        if (!used[j])
        {
            // i番目の本を購入
            sum_money += cost[j];
            // スキルを吸収
            for (int k = 0; k < M; k++)
            {
                skills[k] += point[j][k];
            }
            used[j] = true;
            dfs(j, sum_money);
            used[j] = false;
            sum_money -= cost[j];
            // スキルを吸収
            for (int k = 0; k < M; k++)
            {
                skills[k] -= point[j][k];
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
        for (int j = 0; j < M; j++)
        {
            cin >> point[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill_n(used, N, false);
        fill_n(skills, M, 0);
        for (int j = 0; j < M; j++)
        {
            skills[j] += point[i][j];
        }
        dfs(i, cost[i]);
    }

    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}