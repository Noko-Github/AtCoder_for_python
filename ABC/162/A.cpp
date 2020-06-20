#include <stdlib.h>
#include <iostream>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        if (i % 3 != 0 && i % 5 != 0)
        {
            ans += i;
        }
    }

    cout << ans << endl;
    return 0;
}