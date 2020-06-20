#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int X, N;
    cin >> X >> N;

    if (N == 0)
    {
        cout << X << endl;
        return 0;
    }

    vector<int> P;
    vector<int> not_P;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        P.push_back(p);
    }
    sort(P.begin(), P.end());
    int j = 0;
    for (int i = 0; i <= 101; i++)
    {
        if (P[j] == i)
        {
            j++;
        }
        else
        {
            not_P.push_back(i);
        }
    }

    int ans = 100;
    int min_value = 100;
    for (auto a : not_P)
    {
        if (min_value > abs(X - a))
        {
            ans = a;
            min_value = abs(X - a);
        }
    }

    cout << ans << endl;
    return 0;
}