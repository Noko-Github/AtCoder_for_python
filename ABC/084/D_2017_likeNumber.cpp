#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N = 100010;
    int Q;
    cin >> Q;
    vector<bool> prime_numbers(N, true);
    // Sieve of Eratosthenes
    prime_numbers[0] = false;
    prime_numbers[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!prime_numbers[i])
            continue;
        for (int j = i * 2; j < N; j = j + i)
        {
            prime_numbers[j] = false;
        }
    }

    // 2017-likeかどうか
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            continue;
        if (prime_numbers[i] && prime_numbers[(i + 1) / 2])
            a[i] = 1;
    }

    // 累積和を計算
    vector<long long> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        sum[i + 1] = a[i] + sum[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        r++;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}