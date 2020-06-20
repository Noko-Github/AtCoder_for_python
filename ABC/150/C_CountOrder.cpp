#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt = 0;
int P[8];
int Q[8];
ll a, b;
vector<ll> ans;

void bfs(bool used[], vector<int> array, int limit, int A[], ll &target)
{
    if (array.size() == limit)
    {
        cnt++;
        // 一致するか確認
        for (int i = 0; i < limit; i++)
        {
            if (array[i] != A[i])
            {
                return;
            }
        }
        target = cnt;
    }

    for (int i = 1; i <= limit; i++)
    {
        if (used[i] == false)
        {
            used[i] = true;
            array.push_back(i);
            bfs(used, array, limit, A, target);
            used[i] = false;
            array.pop_back();
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i];
    }

    // 順列を幅優先探索で作成
    for (int i = 1; i <= N; i++)
    {
        bool used[N + 1];
        fill_n(used, N + 1, false);
        vector<int> array;
        used[i] = true;
        array.push_back(i);
        bfs(used, array, N, P, a);
    }

    cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        bool used[N + 1];
        fill_n(used, N + 1, false);
        vector<int> array;
        used[i] = true;
        array.push_back(i);
        bfs(used, array, N, Q, b);
    }

    cout << abs(a - b) << endl;

    return 0;
}