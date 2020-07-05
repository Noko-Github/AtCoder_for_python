#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<string> field;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int H, W, N;

int bfs(int y, int x, char to)
{

    int dist[1000][1000];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dist[i][j] = -1;
        }
    }
    dist[y][x] = 0;

    queue<P> que;
    que.push(P(y, x));

    while (!que.empty())
    {

        P p = que.front();
        que.pop();
        int y, x;
        tie(y, x) = p;

        if (field[y][x] == to)
        {
            return dist[y][x];
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // エリア外であればcontinue;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] == 'X')
            {
                continue;
            }

            // 未訪問の場合
            if (dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                que.push(P(ny, nx));
            }
        }
    }

    return 0;
}

int main()
{
    cin >> H >> W >> N;

    for (int y = 0; y < H; y++)
    {
        string s;
        cin >> s;
        // Sは0置換（後続処理のため）
        replace(s.begin(), s.end(), 'S', '0');
        field.push_back(s);
    }

    // startの場所があればBFS開始
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        char from = to_string(i)[0];
        char to = to_string(i + 1)[0];
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                if (field[y][x] == from)
                {
                    ans += bfs(y, x, to);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}