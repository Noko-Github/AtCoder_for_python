#include <bits/stdc++.h>
using namespace std;

int N;
int max_count = 0;
vector<vector<int>> field;

void search(int y, int x, int sum)
{
    if (y == 1 && x == N - 1)
    {
        if (max_count < sum)
        {
            max_count = sum;
        }
        return;
    }

    if (x + 1 < N)
    {
        search(y, x + 1, sum + field[y][x + 1]);
    }
    if (y == 0)
    {
        search(1, x, sum + field[1][x]);
    }

    return;
}

int main()
{
    cin >> N;
    field = vector<vector<int>>(2, vector<int>(N, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> field[i][j];
        }
    }

    search(0, 0, field[0][0]);

    cout << max_count;
    return 0;
}
