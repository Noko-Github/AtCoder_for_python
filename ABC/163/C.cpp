#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000010;
int G[MAX_N];

int main()
{
    int N;
    cin >> N;
    fill_n(G, N, 0);
    for (int i = 1; i < N; i++)
    {
        int number;
        cin >> number;
        number--;
        G[number]++;
    }

    for (int i = 0; i < N; i++)
    {
        cout << G[i] << endl;
    }
    return 0;
}