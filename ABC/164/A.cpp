#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int S, W;

    cin >> S >> W;

    if (S <= W)
    {
        cout << "unsafe" << endl;
    }
    else
    {
        cout << "safe" << endl;
    }
    return 0;
}