#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll A, B, N;
    cin >> A >> B >> N;

    ll x;
    if (N < B - 1)
    {
        x = N;
    }
    else
    {
        x = B - 1;
    }
    cout << A * (x % B) / B << endl;
    return 0;
}