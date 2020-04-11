#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> prime_count;
int main()
{
    ll N, TMP;
    cin >> N;

    TMP = N;
    for (ll i = 2; i * i < TMP; i++)
    {
        // 約数判定
        while (N % i == 0)
        {
            N = N / i;
            prime_count.push_back(i);
        }
    }

    if (N != 1)
    {
        prime_count.push_back(N);
    }

    cout << TMP << ":";
    for (ll prime : prime_count)
    {
        cout << " " << prime;
    }
    cout << endl;
}