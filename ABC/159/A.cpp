#include <bits/stdc++.h>
using namespace std;

// aCb
int comb(int a)
{
    int bunshi = 1;
    for (int i = 0; i < 2; i++)
    {
        bunshi *= (a - i);
    }

    return bunshi / 2;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int result = 0;
    if (N > 1)
    {
        // n! / 2 * (N-2)!
        result += comb(N);
    }

    if (M > 1)
    {

        result += comb(M);
    }

    cout << result;

    return 0;
}