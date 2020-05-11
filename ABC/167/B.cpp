#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    if (K <= A)
    {
        cout << K << endl;
    }
    else
    {
        cout << A - (K - A - B) << endl;
    }
    return 0;
}