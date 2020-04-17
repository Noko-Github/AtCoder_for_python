#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[100], B[100], minx = 1e+18;

ll solve(ll v1, ll v2)
{
    ll V1 = 0;
    for (int i = 0; i < N; i++)
    {
        V1 += abs(v1 - A[i]);
        V1 += abs(A[i] - B[i]);
        V1 += abs(B[i] - v2);
    }
    return V1;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    vector<ll> E;
    for (int i = 0; i < N; i++)
    {
        E.push_back(A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        E.push_back(B[i]);
    }
    for (ll v1 : E)
    {
        for (ll v2 : E)
        {
            minx = min(minx, solve(v1, v2));
        }
    }

    cout << minx << endl;
    return 0;
}