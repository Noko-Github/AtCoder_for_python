#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_N = 100;
int d[MAX_N]; // 行きがけ順のタイムスタンプ
int f[MAX_N]; // 帰りがけ順のタイムスタンプ
vector<int> G[MAX_N];
int timestamp = 1;
bool seen[MAX_N];

void dfs(int i)
{
    d[i] = timestamp;
    for (int target : G[i])
    {
        if (!seen[target])
        {
            seen[target] = true;
            timestamp = timestamp + 1;
            dfs(target);
        }
    }
    timestamp = timestamp + 1;
    f[i] = timestamp;
}

int main()
{
    int N;
    cin >> N;
    rep(i, N)
    {

        int id, u;
        cin >> id >> u;
        rep(j, u)
        {
            int target;
            cin >> target;
            target--; // zero-indexedに変換
            G[i].push_back(target);
        }
    }

    fill_n(seen, N, false);
    seen[0] = true;
    dfs(0);

    rep(i, N)
    {
        int id = i + 1;
        cout << id << " " << d[i] << " " << f[i] << endl;
    }

    return 0;
}