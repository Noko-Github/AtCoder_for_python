#include <iostream>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)

int main(void)
{
    int N;
    cin >> N;

    int A[N];
    rep(i, N)
    {
        int k;
        cin >> k;
        A[k - 1] = i + 1;
    }

    rep(i, N) cout << A[i] << " ";
    cout << endl;
}