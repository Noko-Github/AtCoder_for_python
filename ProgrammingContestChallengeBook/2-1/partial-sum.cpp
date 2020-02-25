#include <iostream>
#include <vector>
using namespace std;

#define rep(i, c) for (int i = 0; i < (int)c; i++)

bool dfs(vector<int> X, int i, int sum, int n, int k)
{
    if (i == n)
    {
        return sum == k;
    }

    if (dfs(X, i + 1, sum + X[i], n, k))
        return true;

    if (dfs(X, i + 1, sum, n, k))
        return true;

    return false;
}

int main(void)
{
    int n, k;
    cin >> n;
    vector<int> X(n);
    rep(i, n) cin >> X[i];

    if (dfs(X, 0, 0, n, k))
        printf("YES¥n");
    else
        printf("NO¥n");
}
