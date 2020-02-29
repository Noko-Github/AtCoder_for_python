#include <iostream>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
int coin[6] = {1, 5, 10, 50, 100, 500};

int main(void)
{
    int array[7];
    rep(i, 7)
    {
        cin >> array[i];
    }

    int A = array[6];
    int count = 0;
    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / coin[i], array[i]);
        A -= t * coin[i];
        count += t;
    }

    cout << count;
    return 0;
}