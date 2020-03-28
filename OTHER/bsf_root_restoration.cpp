#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{

    int height, width;
    cin >> height >> width;

    vector<string> field(height);
    for (int h = 0; h < height; ++h)
    {
        cin >> field[h];
    }

    int sx, sy, gx, gy;
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            if (field[h][w] == 'S')
            {
                sx = h;
                sy = w;
            }
            if (field[h][w] == 'G')
            {
                gx = h;
                gy = w;
            }
        }
    }

    vector<vector<int>> dist(height, vector<int>(width, -1));
    dist[sx][sy] = 0; // スタートを 0 に

    vector<vector<int>> prev_x(height, vector<int>(width, -1));
    vector<vector<int>> prev_y(height, vector<int>(width, -1));

    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));

    while (!que.empty())
    {
        pair<int, int> current_pos = que.front();
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop();

        for (int direction = 0; direction < 4; direction++)
        {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width)
                continue;
            if (field[next_x][next_y] == '#')
                continue;

            if (dist[next_x][next_y] == -1)
            {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
                prev_x[next_x][next_y] = x;
                prev_y[next_x][next_y] = y;
            }
        }
    }

    /* 各マスへのスタートからの最短距離を見てみる */
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            if (field[h][w] != '.' && field[h][w] != 'G')
                cout << std::setw(3) << field[h][w];
            else
                cout << std::setw(3) << dist[h][w];
        }
        cout << endl;
    }
    cout << endl;

    int x = gx, y = gy;
    while (x != -1 && y != -1)
    {
        field[x][y] = 'o';

        int px = prev_x[x][y];
        int py = prev_y[x][y];
        x = px, y = px;
    }

    return 0;
}