#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    int a, b;
    cin >> n >> s;
    a = 0;
    b = n - 1;

    bool left = true;
    while (a <= b)
    {
        for (int i = 0; i + a <= b; i++)
        {
            if (s[a + i] < s[b - i])
            {
                left = true;
                break;
            }
            else if (s[a + i] > s[b - i])
            {
                left = false;
                break;
            }
        }

        if (left)
            cout << s[a++];
        else
            cout << s[b--];
    }

    return 0;
}