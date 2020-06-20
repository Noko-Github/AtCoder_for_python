#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int X, Y, Z, TMP;
    cin >> X >> Y >> Z;
    TMP = X;
    X = Y;
    Y = TMP;
    TMP = Z;
    Z = X;
    X = TMP;

    cout << X << " " << Y << " " << Z << endl;
    return 0;
}