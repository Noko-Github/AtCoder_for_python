#include <bits/stdc++.h>
using namespace std;
int main()
{
    long N, M;

    cin >> N >> M;
    long ans = 1;
    for (long int i = 1; i * i <= M; i++)
    {

        if (M % i != 0)
            continue;

        long B = M / i;
        if (long(i * N) <= M)
        {
            ans = max(ans, i);
        }
        if (long(B * N) <= M)
        {
            ans = max(ans, B);
        }
    }

    cout << ans << endl;

    return 0;
}