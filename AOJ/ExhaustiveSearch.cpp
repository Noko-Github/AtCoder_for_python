#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int m;
        cin >> m;
        bool ok = false;
        for (int bit = 0; bit < (1 << n); bit++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (bit & (1 << j))
                {
                    sum += A[j];
                }
            }
            if (sum == m)
            {
                cout << "yes" << endl;
                ok = true;
                break;
            }
        }
        if (!ok)
            cout << "no" << endl;
    }

    return 0;
}