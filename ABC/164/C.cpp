#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    map<string, int> G{};

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        string item;
        cin >> item;
        if (G.count(item) == 0)
        {
            ans++;
            G[item] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}