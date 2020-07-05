#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s = "abcdefghijklmnopqrstuvwxyz";

    ll n;
    cin >> n;
    ll mod = 26;
    stack<ll> stack;
    while (n > 26)
    {
        stack.push(n % mod);
        bool flag = false;
        if (n % mod == 0)
        {
            flag = true;
        }
        n = n / mod;
        if (flag)
        {
            n = n - 1;
        }
    }
    stack.push(n % mod);

    while (!stack.empty())
    {
        ll a = stack.top();
        stack.pop();
        if (a == 0)
        {
            a = 25;
        }
        else
        {
            a = a - 1;
        }
        cout << s[a];
    }
    cout << endl;
    return 0;
}