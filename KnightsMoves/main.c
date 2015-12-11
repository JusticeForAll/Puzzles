#include <stdio.h>
#include <time.h>
#include "boardFiller.h"

#define DIMENSION 8

int main()
{
    byte** board;
    byte i, j;
    time_t t;

    srand((unsigned) time(&t));

    board = malloc(DIMENSION * sizeof(byte*));

    for(i = 0; i < DIMENSION; ++i)
        board[i] = malloc(DIMENSION * sizeof(byte));

    for(i = 0; i < DIMENSION; ++i)
        for(j = 0; j < DIMENSION; ++j)
            board[i][j] = 0;

    fillBoard(board, rand() % DIMENSION, rand() % DIMENSION, DIMENSION);

    for(i = 0; i < DIMENSION; ++i)
    {
        for(j = 0; j < DIMENSION; ++j)
        {
            if(!board[i][j])
            {
                printf("ERROR: empty slot on the board at %d %d!!!\n", i, j);
                return 1;
            }
            else printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < DIMENSION; ++i)
        free(board[i]);
    free(board);

    return 0;
}