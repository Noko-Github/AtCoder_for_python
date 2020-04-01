#include <bits/stdc++.h>
using namespace std;

int fib[45];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        if (i < 2)
        {
            fib[i] = 1;
        }
        else
        {
            fib[i] = fib[i - 2] + fib[i - 1];
        }
    }

    cout << fib[N] << endl;
    return 0;
}