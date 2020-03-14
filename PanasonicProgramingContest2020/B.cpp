#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll H, W;
    cin >> H >> W;

    ll a = (W + 1) / 2;
    ll b = (H + 1) / 2;
    ll c = W / 2;
    ll d = H / 2;

    if (W == 1 || H == 1)
    {
        cout << 1;
    }
    else
    {
        cout << a * b + c * d;
    }

    return 0;
}