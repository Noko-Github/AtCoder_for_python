#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll MAX_N = 1000010;

bool b_search(int l, int r, P target, vector<P> vec)
{
    ll ty, tx;
    tie(ty, tx) = target;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll vy, vx;
        tie(vy, vx) = vec[mid];
        if (vy == ty)
        {
            if (vx == tx)
            {
                return true;
            }
            else if (vx < tx)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        else if (vy < ty)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    return false;
}

int main()
{
    int M;
    cin >> M;
    vector<P> target;
    for (int m = 0; m < M; m++)
    {
        ll x, y;
        cin >> x >> y;
        target.push_back(P(y, x));
    }

    // 初期化
    // for (ll y = 0; y < MAX_N; y++)
    // {
    //     for (ll x = 0; x < MAX_N; x++)
    //     {
    //         is_exist[y][x] = false;
    //     }
    // }

    int N;
    cin >> N;
    vector<P> picture;
    for (int n = 0; n < N; n++)
    {
        ll x, y;
        cin >> x >> y;
        picture.push_back(P(y, x));
    }
    sort(target.begin(), target.end());
    sort(picture.begin(), picture.end());

    // 元の写真のそれぞれの座標の差を記録
    vector<P> diff;
    for (int i = 0; i < target.size() - 1; i++)
    {
        ll y, x, ny, nx;
        tie(y, x) = target[i];
        tie(ny, nx) = target[i + 1];
        ll dy = ny - y;
        ll dx = nx - x;
        diff.push_back(P(dy, dx));
    }

    // 各正座について差分が通るか確認。計算量はO(MN)
    for (auto p : picture)
    {
        bool flag = true;
        ll y, x;
        tie(y, x) = p;
        for (auto d : diff)
        {
            ll ny, nx;
            tie(ny, nx) = d;
            y += ny;
            x += nx;

            // 2分木探索で検索
            if (!b_search(-1, picture.size(), P(y, x), picture))
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            // 平行移動を計算
            ll tx, ty, px, py;
            tie(py, px) = p;
            tie(ty, tx) = target[0];
            cout << px - tx << " " << py - ty << endl;
            break;
        }
    }

    return 0;
}