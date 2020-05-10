#include <bits/stdc++.h>
using namespace std;

// 2次元累積和
int sum_J[1010][1010] = {0};
int sum_O[1010][1010] = {0};
int sum_I[1010][1010] = {0};
int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    string field[M];
    for (int i = 0; i < M; i++)
    {
        cin >> field[i];
    }

    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (field[y][x] == 'J')
            {
                sum_J[y + 1][x + 1] = sum_J[y][x + 1] + sum_J[y + 1][x] - sum_J[y][x] + 1;
            }
            else
            {
                sum_J[y + 1][x + 1] = sum_J[y][x + 1] + sum_J[y + 1][x] - sum_J[y][x];
            }
            if (field[y][x] == 'O')
            {
                sum_O[y + 1][x + 1] = sum_O[y][x + 1] + sum_O[y + 1][x] - sum_O[y][x] + 1;
            }
            else
            {
                sum_O[y + 1][x + 1] = sum_O[y][x + 1] + sum_O[y + 1][x] - sum_O[y][x];
            }
            if (field[y][x] == 'I')
            {
                sum_I[y + 1][x + 1] = sum_I[y][x + 1] + sum_I[y + 1][x] - sum_I[y][x] + 1;
            }
            else
            {
                sum_I[y + 1][x + 1] = sum_I[y][x + 1] + sum_I[y + 1][x] - sum_I[y][x];
            }
        }
    }

    while (K > 0)
    {
        int from_x, from_y, to_x, to_y;
        cin >> from_y >> from_x >> to_y >> to_x;

        int ans_J = sum_J[to_y][to_x] - sum_J[to_y][from_x - 1] - sum_J[from_y - 1][to_x] + sum_J[from_y - 1][from_x - 1];
        int ans_O = sum_O[to_y][to_x] - sum_O[to_y][from_x - 1] - sum_O[from_y - 1][to_x] + sum_O[from_y - 1][from_x - 1];
        int ans_I = sum_I[to_y][to_x] - sum_I[to_y][from_x - 1] - sum_I[from_y - 1][to_x] + sum_I[from_y - 1][from_x - 1];

        cout << ans_J << " " << ans_O << " " << ans_I << endl;
        K--;
    }

    return 0;
}