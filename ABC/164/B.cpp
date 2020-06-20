#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    while (A > 0 && C > 0)
    {
        C -= B;
        if (C <= 0)
        {
            cout << "Yes" << endl;
            break;
        }
        A -= D;
        if (A <= 0)
        {
            cout << "No" << endl;
            break;
        }
    }
    return 0;
}