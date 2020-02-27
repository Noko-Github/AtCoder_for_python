#include <iostream>;
#include <utility>;
#include <queue>;
using namespace std;

char field[6][6] = {
    {'#', 'S', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.'},
    {'.', '#', '.', '#', '.', '.'},
    {'#', '.', '.', '#', '#', '#'},
    {'#', '#', '.', '.', 'G', '#'}};

typedef pair<int, int> P;

int Y = sizeof(field) / sizeof(field[0]);
int X = sizeof(field[0]) / sizeof(field[0][0]);

int count = 0;

void bfs(queue<P> p)
{
}

int main()
{
    queue<P> que;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (field[y][x] == 'S')
            {
                que.push(P(y, x));
                bfs(que);
            }
        }
    }

    return 0;
}
