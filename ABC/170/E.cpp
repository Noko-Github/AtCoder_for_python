#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n); // レート
    vector<int> b(n); // 所属する幼稚園

    vector<multiset<int>> s(200000);
    multiset<int> maxs;

    auto getMax = [&](int yochienNum) {
        // 幼稚園から最大値を取得する
        if (s[yochienNum].size() == 0)
            return -1;
        return *s[yochienNum].rbegin();
    };

    auto deleteYochien = [&](int yochienNum) {
        // 幼稚園の最大値を削除する
        int x = getMax(yochienNum);
        if (x == -1)
            return;
        maxs.erase(maxs.find(x));
    };

    auto addYochien = [&](int yochienNum) {
        // 幼稚園を最大値に追加する
        int x = getMax(yochienNum);
        if (x == -1)
            return;
        maxs.insert(x);
    };

    auto addEnji = [&](int score, int yochienNum) {
        deleteYochien(yochienNum);
        s[yochienNum].insert(score);
        addYochien(yochienNum);
    };

    auto deleteEnji = [&](int score, int yochienNum) {
        deleteYochien(yochienNum);
        s[yochienNum].erase(s[yochienNum].find(score));
        addYochien(yochienNum);
    };

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        addEnji(a[i], b[i]);
    }

    for (int i = 0; i < q; i++)
    {
        ll c, d;
        cin >> c >> d;
        c--;
        // c番目の園児をdの幼稚園に移動させる→一旦元の幼稚縁から園児を削除してmaxを更新
        deleteEnji(a[c], b[c]);
        b[c] = d;
        addEnji(a[c], b[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
    return 0;
}