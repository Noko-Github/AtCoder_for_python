#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

char field[6][6] = {
    {'#', 'S', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.'},
    {'.', '#', '.', '#', '.', '.'},
    {'#', '.', '.', '#', '#', '#'},
    {'#', '#', '.', '.', 'G', '#'}};

typedef pair<int, int> P;

int Y = sizeof(field) / sizeof(field[0]);
int X = sizeof(field[0]) / sizeof(field[0][0]);

int d[6][6];

int INF = 1000;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<P> p)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            d[i][j] = INF;
        }
    }

    P result = p.front();
    int y = result.first;
    int x = result.second;

    d[y][x] = 0;

    while (p.size())
    {
        P now = p.front();
        p.pop();
        if (field[now.first][now.second] == 'G')
        {
            return d[now.first][now.second];
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i], nx = now.second + dx[i];

            if (0 <= ny && ny < Y && 0 < nx && nx < X && field[ny][nx] != '#' && d[ny][nx] == INF)
            {
                p.push(P(ny, nx));
                d[ny][nx] = d[now.first][now.second] + 1;
            }
        }
    }
    return 0;
}

int main()
{
    queue<P> que;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (field[y][x] == 'S')
            {
                que.push(P(y, x));
                int count = bfs(que);
                printf("%d\n", count);
                return 0;
            }
        }
    }

    return 0;
}
