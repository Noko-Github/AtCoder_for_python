#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    int count = 0;
    int now = 10000000;
    for (int i = 0; i < N; i++)
    {
        if (now != x[i])
        {
            count++;
            now = x[i];
        }
    }

    cout << count;
}