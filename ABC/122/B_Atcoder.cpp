#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.size();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);

    cout << ans << endl;
    return 0;
}
