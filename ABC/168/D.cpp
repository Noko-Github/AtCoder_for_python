#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_V = 100010;
vector<int> G[MAX_V];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    bool seen[N];
    int ans[N];
    fill_n(seen, N, false);
    fill_n(ans, N, -1);
    queue<int> que;
    que.push(0);
    seen[0] = true;
    while (!que.empty())
    {
        int from = que.front();
        que.pop();
        for (int to : G[from])
        {
            if (!seen[to])
            {
                seen[to] = true;
                ans[to] = from;
                que.push(to);
            }
        }
    }

    // 更新できていないものがないかチェック
    for (int i = 1; i < N; i++)
    {
        if (ans[i] == -1)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i < N; i++)
    {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}