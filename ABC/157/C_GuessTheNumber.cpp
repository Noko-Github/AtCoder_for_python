#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> v[2];

    for (int i = 0; i < M; i++)
    {
        int s, c;
        cin >> s >> c;
        v[0].push_back(--s);
        v[1].push_back(c);
    }

    for (int i = 0; i <= 999; i++)
    {
        bool false_flag = 0;
        string i_str = to_string(i);
        if (i_str.size() != N)
            continue;

        for (int j = 0; j < M; j++)
        {
            if (i_str[v[0][j]] != v[1][j] + '0')
            {
                false_flag = 1;
                break;
            }
        }

        if (false_flag == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}