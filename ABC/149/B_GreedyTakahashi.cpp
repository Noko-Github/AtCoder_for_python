#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;
    A -= K;
    if (A < 0)
    {
        B += A;
        A = 0;
    }

    cout << A << " " << B << endl;
    return 0;
}