#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

struct Edge
{
    P a, b;
    double cost;
    Edge(P a, P b, double cost) : a(a), b(b), cost(cost){};

    bool operator<(const Edge &right) const
    {
        return cost > right.cost;
    };
};

double cal(P a, P b)
{
    int x1, y1, x2, y2;
    tie(x1, y1) = a;
    tie(x2, y2) = b;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check(Edge edge, vector<vector<bool>> field)
{
    int x1, y1, x2, y2;
    tie(x1, y1) = edge.a;
    tie(x2, y2) = edge.b;
    int nx1 = (x2 - y2 + y1);
    int ny1 = (y2 + x2 - x1);
    int nx2 = (x1 - y2 + y1);
    int ny2 = (y1 + x2 - x1);
    if (nx1 < 0 || nx2 < 0 || ny1 < 0 || ny2 < 0)
        return false;
    if (field[ny1][nx1] && field[ny2][nx2])
        return true;
    return false;
}
int main()
{
    int N;
    cin >> N;
    vector<vector<bool>> field(5010, vector<bool>(5010, false));

    int X[N];
    int Y[N];
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        field[y][x] = true;
        X[i] = x;
        Y[i] = y;
    }

    vector<Edge> edges;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            P a = P(X[i], Y[i]);
            P b = P(X[j], Y[j]);
            edges.push_back(Edge(a, b, cal(a, b)));
        }
    }
    sort(edges.begin(), edges.end());
    for (Edge edge : edges)
    {
        if (check(edge, field))
        {
            cout << edge.cost * edge.cost << endl;
            return 0;
        }
    }
    return 0;
}