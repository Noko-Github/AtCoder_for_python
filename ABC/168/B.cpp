#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    int K;
    cin >> K >> S;
    int len = S.length();

    if (len <= K)
    {
        cout << S << endl;
    }
    else
    {
        cout << S.substr(0, K) + "..." << endl;
    }

    return 0;
}