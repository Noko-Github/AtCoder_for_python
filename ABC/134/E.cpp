#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    deque<int> s;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        int p = lower_bound(s.begin(), s.end(), a) - s.begin();
        if (p == 0)
        {
            s.push_front(a);
        }
        else
        {
            s[p - 1] = a;
        }
    }

    cout << s.size() << endl;
    return 0;
}