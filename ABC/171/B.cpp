#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<int> a;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        a.push_back(cost);
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}