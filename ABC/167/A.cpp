#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S, T;
    cin >> S >> T;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != T[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}