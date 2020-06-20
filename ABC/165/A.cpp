#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int K, A, B;
    cin >> K >> A >> B;

    if (A <= B / K * K)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NG" << endl;
    }

    return 0;
}