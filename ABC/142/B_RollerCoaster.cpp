#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(void)
{
    int N, K;
    cin >> N;
    cin >> K;
    int h[N];
    rep(i, N) cin >> h[i];

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (h[i] >= K)
        {
            count = count + 1;
        }
    }

    printf("%d", count);
    return 0;
}