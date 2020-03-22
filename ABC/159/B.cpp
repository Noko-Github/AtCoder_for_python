#include <bits/stdc++.h>
using namespace std;

bool isKaibunn(string s)
{
    if (s.size() == 1)
    {
        return true;
    }
    if (s.size() < 3)
    {
        return false;
    }

    bool result = true;
    int i = 0;
    int j = s.size() - 1;
    while (i + 1 < j)
    {
        if (s[i] != s[j])
        {
            result = false;
            break;
        }

        i++;
        j--;
    }

    return result;
}

int main()
{
    string S;
    cin >> S;

    int len = S.size();

    // cout << S.substr(0, (len - 1) / 2) << endl;
    // cout << S.substr((len + 3) / 2 - 1) << endl;
    bool a = isKaibunn(S.substr(0, (len - 1) / 2));
    bool b = isKaibunn(S.substr((len + 3) / 2 - 1));
    bool c = isKaibunn(S);

    if (a && b && c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}