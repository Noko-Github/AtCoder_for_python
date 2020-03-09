#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    map<string, int> d;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        d[s]++;
    }

    int mx = 0;
    for (auto p : d)
    {
        mx = max(mx, p.second);
    }
    for (auto p : d)
    {
        if (p.second != mx)
            continue;
        cout << p.first << " ";
    }
}