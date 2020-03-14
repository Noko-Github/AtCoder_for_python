#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt = 0;
ll N;

bool check(ll x)
{
    bool ok = true;
    bool digit_flag[10] = {false};
    while (x > 0)
    {
        int c = x % 10;
        if (c == 3 || c == 5 || c == 7)
        {
            if (!digit_flag[c])
                digit_flag[c] = true;
            x /= 10;
        }
        else
        {
            ok = false;
            break;
        }
    }

    if (digit_flag[3] != true || digit_flag[5] != true || digit_flag[7] != true)
    {
        ok = false;
    }

    return (ok == true);
}

void dfs(ll x)
{
    if (x > N)
        return;

    if (check(x))
        cnt++;

    dfs(x * 10 + 3);
    dfs(x * 10 + 5);
    dfs(x * 10 + 7);
}

int main()
{
    cin >> N;
    dfs(0);
    cout << cnt << endl;
    return 0;
}