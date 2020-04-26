#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()

typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1LL << 60);

vector<Int> edge[108000];
Int dist[1008000];
bool zombie[108000];
bool danger[108000];
Int pcost, qcost;
Int n, m, k, s, x, a, b;

void dijkstra(Int start)
{
}
int main()
{
    cin >> n >> m >> k >> s;
    cin >> pcost >> qcost;

    queue<Int> q;

    for (Int i = 0; i < k; i++)
    {
        cin >> x;
        zombie[x] = true;
        q.push(x);
    }

    for (Int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (Int i = 0; i <= s; i++)
    {
        if (q.empty())
            break;
        for (Int j = q.size() - 1; j >= 0; j--)
        {
            Int from = q.front();
            q.pop();
            if (danger[from])
                continue;
            danger[from] = true;
        }
    }
    return 0;
}