#include <bits/stdc++.h>
using namespace std;

// int型をvector型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えるか
vector<int> IntergerToVector(int bit, int N)
{
    vector<int> S;
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i))
        {
            S.push_back(i);
        }
    }

    return S;
}

int main()
{
    int N, W;

    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    // bit全探索
    bool exist = false;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        vector<int> S = IntergerToVector(bit, N);

        int sum = 0;
        for (int i : S)
            sum += a[i];

        if (sum == W)
            exist = true;
    }

    if (exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}