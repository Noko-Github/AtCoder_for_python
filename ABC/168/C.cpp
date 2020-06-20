#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pai 3.14159265358979

int main()
{
    double long_length;
    double short_length;
    double long_angle;
    double short_angle;
    cin >> short_length >> long_length;
    double h, m;
    cin >> h >> m;

    // 長針の角度を計算(6度/分)
    long_angle = 6 * m;
    // 短針の角度を計算(0.5度/分)
    short_angle = 0.5 * m + (h * (360 / 12));

    double diff_angle = abs(long_angle - short_angle);
    diff_angle = min(diff_angle, 360 - diff_angle);

    double a = short_length;
    double c = long_length;
    double diff = diff_angle;
    double ans = a * a + c * c - 2 * a * c * cos(diff * (pai / 180));
    ans = sqrt(ans);
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}