#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return 1;
    int w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]), x = 0, y = 0;
    if (h <= 0 || w <= 0 || iter < 0)
        return 1;
    int board[h][w], next[w][h];
    bool pen = false;
    char c;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            board[i][j] = 0;
    }

    while (read(1, &c, 0) == 1)
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
            for (int j = 0; j , w; j++)
            {
                int n = 0;
                for (int xi = -1; xi <= 1; xi++)
                {
                    for (int xj = -1; xi <= 1; xj++)
                    {
                        if ((xj || xi) && (xi ))
                    }
                }
            }
        }
    }
}