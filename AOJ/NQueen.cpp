#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX_N = 8;
vector<int> rows(MAX_N, -1);

bool check(int row, int col)
{
    for (int k = 0; k < MAX_N; k++)
    {
        if (rows[k] == -1)
            continue;
        // 列方向のチェック
        if (col == rows[k])
            return false;
        // 対角線のチェック
        if (abs(row + col) == abs(rows[k] + k))
            return false;
        if ((row - col == k - rows[k]) || (col - row == rows[k] - k))
            return false;
    }

    return true;
}

bool dfs(int row)
{
    if (row == 8)
    {
        for (int i = 0; i < MAX_N; i++)
        {
            for (int j = 0; j < MAX_N; j++)
            {
                cout << (rows[i] == j ? 'Q' : '.');
            }
            cout << endl;
        }
        return true;
    }

    if (rows[row] == -1)
    {
        for (int col = 0; col < MAX_N; col++)
        {
            if (check(row, col))
            {
                rows[row] = col;
                if (dfs(row + 1))
                    return true;
                rows[row] = -1;
            }
        }
    }
    else
    {
        if (dfs(row + 1))
            return true;
    }
    return false;
}

int main()
{

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int row, col;
        cin >> row >> col;
        rows[row] = col;
    }

    dfs(0);

    return 0;
}