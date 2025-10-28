#include <stdlib.h>
#include <stdio.h>

void printBoard(int **board, int rows, int *cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gameOfLife(int **board, int boardSize, int *boardColSize)
{
    int **muted = malloc(sizeof(int *) * boardSize);
    if (muted == NULL)
        return;
    for (int i = 0; i < boardSize; i++)
    {
        muted[i] = calloc(boardColSize[i], sizeof(int));
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            int memo[3][3] = {0};

            if (i > 0 && j > 0 && board[i - 1][j - 1] == 1)
                memo[0][0] = 1;
            if (i > 0 && board[i - 1][j] == 1)
                memo[0][1] = 1;
            if (i > 0 && j + 1 < boardColSize[i - 1] && board[i - 1][j + 1] == 1)
                memo[0][2] = 1;

            if (j > 0 && board[i][j - 1] == 1)
                memo[1][0] = 1;
            if (j + 1 < boardColSize[i] && board[i][j + 1] == 1)
                memo[1][2] = 1;

            if (i + 1 < boardSize && j > 0 && board[i + 1][j - 1] == 1)
                memo[2][0] = 1;
            if (i + 1 < boardSize && board[i + 1][j] == 1)
                memo[2][1] = 1;
            if (i + 1 < boardSize && j + 1 < boardColSize[i + 1] && board[i + 1][j + 1] == 1)
                memo[2][2] = 1;

            int numOfNeighbors = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int z = 0; z < 3; z++)
                {
                    numOfNeighbors += memo[k][z];
                }
            }
            if (board[i][j] == 1)
            {
                if (numOfNeighbors < 2)
                    muted[i][j] = 0;
                else if (numOfNeighbors > 3)
                    muted[i][j] = 0;
                else
                    muted[i][j] = 1;
            }
            else if (board[i][j] == 0)
            {
                if (numOfNeighbors == 3)
                    muted[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            board[i][j] = muted[i][j];
        }
    }
    for (int i = 0; i < boardSize; i++)
        free(muted[i]);
    free(muted);
}

int main(void)
{
    // Example 1: the "blinker" pattern
    // Initial:
    // 0 1 0
    // 0 1 0
    // 0 1 0
    int rows = 3;
    int cols[] = {5, 5, 5};

    int **board = malloc(rows * sizeof(int *));
    int initial[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    for (int i = 0; i < rows; i++)
    {
        board[i] = malloc(cols[i] * sizeof(int));
        for (int j = 0; j < cols[i]; j++)
            board[i][j] = initial[i][j];
    }

    printf("Initial board:\n");
    printBoard(board, rows, cols);

    gameOfLife(board, rows, cols);

    printf("After 1 iteration:\n");
    printBoard(board, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++)
        free(board[i]);
    free(board);

    return 0;
}