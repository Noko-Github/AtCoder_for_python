#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long int x = c - a - b;
    if (x < 0)
    {
        cout << "No";
        return 0;
    }

    if (x * x > 4 * a * b)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}