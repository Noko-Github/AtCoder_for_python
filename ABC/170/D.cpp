#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e+6 + 1;

int main()
{
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    int S[MAX_N];
    fill_n(S, MAX_N, 0);
    for (auto a : A)
    {
        int tmp = a;
        if (S[a] == 0)
        {
            while (a <= MAX_N)
            {
                S[a]++;
                a = a + tmp;
            }
        }
        else
        {
            S[a]++;
        }
    }

    int ans = 0;
    for (auto a : A)
    {
        if (S[a] == 1)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}