#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, A, B;
    cin >> N >> A >> B;

    long long cnt = (N / (A + B)) * A;
    long long amari = (N % (A + B));
    if (amari < A)
    {
        cnt += amari;
    }
    else if (amari > A)
    {
        cnt += A;
    }

    cout << cnt;

    return 0;
}