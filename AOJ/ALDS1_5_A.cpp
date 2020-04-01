#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int bit = 0; bit < (1 << N); bit++)
    {
        int sum = 0;
        for (int i = 0; i < (1 << N); i++)
        {
            if (bit & (1 << i))
            {
                sum += A[i];
            }
        }
        if (sum == M)
        {
            cout << "yes" << endl;
            return 0;
        }
    }

    cout << "no" << endl;

    return 0;
}