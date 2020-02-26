#include <iostream>
using namespace std;

char field[6][6] = {
    {'W', '.', '.', '.', 'W', 'W'},
    {'W', '.', 'W', '.', 'W', 'W'},
    {'W', '.', '.', '.', '.', '.'},
    {'W', 'W', '.', 'W', '.', '.'},
    {'W', 'W', '.', '.', 'W', 'W'},
    {'W', 'W', '.', '.', 'W', 'W'}};

int Y = 6;
int X = 6;

void is_continued_rake(int py, int px)
{
    field[py][px] = '.';

    for (int y = -1; y < 2; y++)
    {
        for (int x = -1; x < 2; x++)
        {
            int ny = py + y;
            int nx = px + x;
            if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
                continue;
            if (field[ny][nx] == 'W')
            {
                is_continued_rake(ny, nx);
            }
        }
    }

    return;
}

int main(void)
{
    int count = 0;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (field[y][x] == 'W')
            {
                is_continued_rake(y, x);
                count += 1;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
