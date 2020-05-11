#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_loop[1000000] = {false};
int loop_nubmer = -1;

int main()
{
    int N;
    ll K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    vector<int> s;
    vector<int> ord(N + 1, -1);
    int c = 1;
    int l = 0;
    {
        int v = 1;
        while (ord[v] == -1)
        {
            ord[v] = s.size();
            s.push_back(v);
            v = a[v - 1];
        }
        c = s.size() - ord[v];
        l = ord[v];
    }

    if (K < l)
        cout << s[K] << endl;
    else
    {
        K -= l;
        K %= c;
        cout << s[l + K] << endl;
    }
    return 0;
}