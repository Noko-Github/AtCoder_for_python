#include <bits/stdc++.h>
using namespace std;

int N;
int max_count = 0;
vector<vector<int>> field;

void search(int y, int x, int sum, vector<vector<int>> field)
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
        search(y, x + 1, sum + field[y][x + 1], field);
    }
    if (y == 0)
    {
        search(1, x, sum + field[1][x], field);
    }

    return;
}

int main()
{
    cin >> N;
    vector<vector<int>> field(2, vector<int>(N, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> field[i][j];
        }
    }

    search(0, 0, field[0][0], field);

    cout << max_count;
    return 0;
}
