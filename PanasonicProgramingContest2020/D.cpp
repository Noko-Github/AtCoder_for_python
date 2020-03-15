#include <bits/stdc++.h>
using namespace std;

int N;

void dfs(string s, char mx)
{
    if (s.size() >= N)
    {
        cout << s << endl;
        return;
    }

    for (char c = 'a'; c <= mx + 1; c++)
    {
        dfs(s + c, max(mx, c));
    }

    return;
}

int main()
{
    cin >> N;

    dfs("", 'a' - 1);

    return 0;
}