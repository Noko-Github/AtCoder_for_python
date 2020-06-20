#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < 3; i++)
    {
        if (S[i] == '7')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}