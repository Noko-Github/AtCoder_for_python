#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q;
    cin >> s >> q;
    bool st = 0;
    vector<char> v[2];
    while (q--)
    {
        int qt;
        cin >> qt;
        if (qt == 1)
        {
            st = !st;
            cout << st;
        }
        else
        {
            int f;
            char c;
            cin >> f >> c, --f;
            v[f ^ st].push_back(c);
        }
    }

    string t;
    for (int i = (int)v[0].size() - 1; ~i; --i)
    {
        cout << "\n";
        cout << "i is " << i << "\n";
        cout << "~i is " << ~i << "\n";
        t += v[0][i];
    }

    t += s;
    for (char c : v[1])
    {
        t += c;
    }

    if (st)
    {
        reverse(t.begin(), t.end());
    }

    cout << t;
}
