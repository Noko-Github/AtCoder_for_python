#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int X, Y;
    cin >> X >> Y;
    for (int i = 0; i <= X; i++)
    {
        if (Y == i * 2 + (X - i) * 4)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}