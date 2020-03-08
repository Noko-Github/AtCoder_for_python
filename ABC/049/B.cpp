#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> strlist(H);

    for (int i = 0; i < H; i++)
    {
        cin >> strlist[i];
    }

    for (int i = 0; i < H; i++)
    {
        cout << strlist[i] << endl;
        cout << strlist[i] << endl;
    }

    return 0;
}