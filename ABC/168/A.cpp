#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    int len = S.length() - 1;

    if (S[len] == '2' || S[len] == '4' || S[len] == '5' || S[len] == '7' || S[len] == '9')
    {
        cout << "hon" << endl;
    }
    else if (S[len] == '0' || S[len] == '1' || S[len] == '6' || S[len] == '8')
    {
        cout << "pon" << endl;
    }
    else if (S[len] == '3')
    {
        cout << "bon" << endl;
    }
    return 0;
}