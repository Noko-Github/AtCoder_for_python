#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;

    if (S.size() < 4)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 4; i <= S.size(); i++)
    {
        for (int j = 0; j < S.size() - (i - 1); j++)
        {
            string sub = S.substr(j, i);
            cout << sub << endl;
            if (stoi(sub) % 2019 == 0)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}