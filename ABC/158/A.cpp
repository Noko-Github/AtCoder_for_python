#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string S = "";
    cin >> S;
    if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A')
        cout << "No";
    else if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B')
        cout << "No";
    else
        cout << "Yes";

    return 0;
}