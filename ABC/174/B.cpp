#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int ans = 0;

    int X, D;
    cin >> X >> D;
    for (int i = 0; i < X; i++)
    {
        ll x, y;
        cin >> x >> y;
        double d = sqrt(x * x + y * y);
        if (d <= D)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}