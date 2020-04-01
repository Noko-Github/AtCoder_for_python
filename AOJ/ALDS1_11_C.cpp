#include <iostream>
#include <vector>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
const int MAX_N = 100;
vector<int> G[MAX_N];
vector<bool> seen(MAX_N, false);

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
            target--;
            G[i].push_back(target);
        }
    }

    // 最短距離を算出
    queue<int> que;
    que.push(0);

    int distance = 0;
    int d[N];
    fill_n(d, N, -1);
    d[0] = 0;
    seen[0] = true;
    while (!que.empty())
    {
        int origin = que.front();
        int distance = d[origin];
        que.pop();
        for (int target : G[origin])
        {
            if (!seen[target])
            {
                seen[target] = true;
                d[target] = distance + 1;
                que.push(target);
            }
        }
    }

    rep(i, N)
    {
        int id = i + 1;
        cout << id << " " << d[i] << endl;
    }

    return 0;
}
