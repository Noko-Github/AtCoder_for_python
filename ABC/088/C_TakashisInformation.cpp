#include <bits/stdc++.h>
using namespace std;

int a[3][3];
int x[3];
int y[3];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int c_i1, c_i2, c_i3;
        cin >> c_i1 >> c_i2 >> c_i3;

        a[i][0] = c_i1;
        a[i][1] = c_i2;
        a[i][2] = c_i3;
    }

    x[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        y[i] = a[0][i] - x[0];
    }
    for (int i = 0; i < 3; i++)
    {
        x[i] = a[i][0] - y[0];
    }

    bool good = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (x[i] + y[j] != a[i][j])
            {
                good = false;
            }
        }
    }

    if (good)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}