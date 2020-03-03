#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
vector<int> pos;
vector<vector<pair<int, int>>> edge;

bool check(int src)
{
    for (int i = 0; i < edge[src].size(); i++)
    {
        int dst = edge[src][i].first;
        int d = edge[src][i].second;

        if (pos[dst] == inf)
        {
            pos[dst] = pos[src] + d;
            if (check(dst) == false)
            {
                return false;
            }
        }
        else if (pos[dst] != pos[src] + d)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    edge = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++)
    {
        int L, R, D;
        cin >> L >> R >> D;
        L--;
        R--;
        edge[L].push_back(make_pair(R, D));
        edge[R].push_back(make_pair(L, -D));
    }

    pos = vector<int>(N, inf);
    for (int i = 0; i < N; i++)
    {
        if (pos[i] != inf)
        {
            continue;
        }

        pos[i] = 0;
    }
    if (check(i) == false)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}