#include <stdlib.h>
#include <iostream>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main()
{
    int K;
    cin >> K;

    ll ans = 0;
    for (int a = 1; a <= K; a++)
    {
        for (int b = 1; b <= K; b++)
        {
            for (int c = 1; c <= K; c++)
            {
                ans += gcd(gcd(a, b), c);
            }
        }
    }

    cout << ans << endl;
    return 0;
}