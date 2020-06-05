#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll limit = 1e18;

int main()
{
    ll a;
    double b;
    cin >> a >> b;
    //a *= int(b * 100 + 0.05);
    printf("%.60f\n", b * 100);
    a *= int(b * 100);
    cout << a / 100 << endl;
    return 0;
}