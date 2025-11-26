#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return (printf("Bad number of arguments\n"), 1);
    int w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]), x = 0, y = 0;
    if (w <= 0 || h <= 0 || iter < 0)
        return (printf("Bad Arguments\n"), 1);
    int board[h][w], next[h][w];
    bool pen = false;
    char c;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            board[i][j] = 0;
    }

    while (read(0, &c, 1) == 1)
    {
        if (c == 'w' && x > 0) x--;
        else if (c == 's' && x < h - 1) x++;
        else if (c == 'd' && y < w - 1) y++;
        else if (c == 'a' && y > 0) y--;
        else if (c == 'x') pen = !pen;
        if (pen) board[x][y] = 1;
    }

    for (int it = 0; it < iter; it++)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int n = 0;
                for (int xi = -1; xi <= 1; xi++)
                {
                    for (int xj = -1; xj <= 1; xj++)
                        if ((xi || xj) && (xi + i >=0 && xi + i < h && xj + j >= 0 && xj + j < w))
                            n += board[i + xi][j + xj];
                }
                next[i][j] = ((board[i][j] && (n == 2 || n == 3)) || (!board[i][j] && n == 3));
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                board[i][j] = next[i][j];
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            board[i][j] ? putchar('0') : putchar(' ');
        putchar('\n');
    }
}