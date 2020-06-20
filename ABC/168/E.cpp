#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<pair<ll, ll>, P> mp;
const ll mod = 1000000007;

struct mint
{
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main()
{
    int N;
    cin >> N;
    ll zero = 0;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (x == 0 && y == 0)
        {
            zero++;
            continue;
        }
        // (1) 単位ベクトルに回転
        ll g = gcd(x, y);
        x /= g;
        y /= g;

        // (3) y < 0の時、180度回転
        if (y < 0)
        {
            x = -x;
            y = -y;
        }

        // (2) x = 0 or y = 0なら同様に正規化
        if (y == 0 && x < 0)
        {
            x = -x;
            y = -y;
        }

        // (4) x <= 0のとき、90度回転
        bool rot90 = false;
        if (x <= 0)
        {
            rot90 = true;
            ll tmp = y;
            y = -x;
            x = tmp;
        }

        // 同じグループに格納
        if (rot90)
        {
            mp[{x, y}].first++;
        }
        else
        {
            mp[{x, y}].second++;
        }
    }

    ll ans = 1;
    for (auto p : mp)
    {
        ll s = p.second.first;
        ll t = p.second.second;

        ll now = 1;

        now = (((now + modpow(2, s, mod)) % mod) - 1) % mod;
        now = (((now + modpow(2, t, mod)) % mod) - 1) % mod;

        now %= mod;
        ans %= mod;
        ans = ans * now % mod;
    }

    ans -= 1; // 何も選ばない
    ans %= mod;
    ans += zero; // x =0, y=0を選ぶ

    cout << ans % mod << endl;
    return 0;
}