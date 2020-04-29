#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    scanf(" %d", &q);
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;

        string x = " "+a;
    }


    int ans = 0;
    for (int i = 1; i <=m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) c[i][j] = c[i-1][j-1]+1;
            else
            {
                c[i][j] = max(c[i][-1], c[i-1][j])
            }
            
        }
    }
    return 0;
}