#include "boardFiller.h"

void fillBoard(byte** board, byte initialX, byte initialY, byte dimension)
{
    fill(board, initialX, initialY, dimension, 1);
}

void fill(byte** board, byte initialX, byte initialY, byte dimension, byte level)
{
    if(level == dimension * dimension + 1 || board[initialX][initialY])
        return;

    byte i = 0;
    byte minX, minY;
    byte minMoves = 9;
    byte numMoves = findNumMoves(board, initialX, initialY, dimension);

    move* possibleMoves = getValidMoves(board, initialX, initialY, numMoves, dimension);

    for(i = 0; i < numMoves; ++i)
    {
        if(possibleMoves[i].numOfMoves < minMoves)
        {
            minMoves = findNumMoves(board, possibleMoves[i].pos.x, possibleMoves[i].pos.y, dimension);
            minX = possibleMoves[i].pos.x;
            minY = possibleMoves[i].pos.y;
        }
    }

    board[initialX][initialY] = level;

    fill(board, minX, minY, dimension, ++level);

    free(possibleMoves);
}

byte findNumMoves(byte** board, byte initialX, byte initialY, byte dimension)
{
    byte count = 0;

    if(initialX + 2 < dimension && initialY + 1 < dimension && !board[initialX + 2][initialY + 1])
        ++count;
    if(initialX + 1 < dimension && initialY + 2 < dimension && !board[initialX + 1][initialY + 2])
        ++count;
    if(initialX + 2 < dimension && initialY - 1 >= 0 && !board[initialX + 2][initialY - 1])
        ++count;
    if(initialX + 1 < dimension && initialY - 2 >= 0 && !board[initialX + 1][initialY - 2])
        ++count;
    if(initialX - 2 >= 0 && initialY - 1 >= 0 && !board[initialX - 2][initialY - 1])
        ++count;
    if(initialX - 1 >= 0 && initialY - 2 >= 0 && !board[initialX - 1][initialY - 2])
        ++count;
    if(initialX - 2 >= 0 && initialY + 1 < dimension && !board[initialX - 2][initialY + 1])
        ++count;
    if(initialX - 1 >= 0 && initialY + 2 < dimension && !board[initialX - 1][initialY + 2])
        ++count;

    return count;
}

move* getValidMoves(byte** board, byte initialX, byte initialY, byte size, byte dimension)
{
    move* arr = malloc(sizeof(move) * size);
    byte count = 0;

    if(initialX + 2 < dimension && initialY + 1 < dimension && !board[initialX + 2][initialY + 1])
    {
        arr[count].pos.x = initialX + 2;
        arr[count].pos.y = initialY + 1;
        arr[count].numOfMoves = findNumMoves(board, initialX + 2, initialY + 1, dimension);
        ++count;
    }
    if(initialX + 1 < dimension && initialY + 2 < dimension && !board[initialX + 1][initialY + 2])
    {
        arr[count].pos.x = initialX + 1;
        arr[count].pos.y = initialY + 2;
        arr[count].numOfMoves = findNumMoves(board, initialX + 1, initialY + 2, dimension);
        ++count;
    }
    if(initialX + 2 < dimension && initialY - 1 >= 0  && !board[initialX + 2][initialY - 1])
    {
        arr[count].pos.x = initialX + 2;
        arr[count].pos.y = initialY - 1;
        arr[count].numOfMoves = findNumMoves(board, initialX + 2, initialY - 1, dimension);
        ++count;
    }
    if(initialX + 1 < dimension && initialY - 2 >= 0  && !board[initialX + 1][initialY - 2])
    {
        arr[count].pos.x = initialX + 1;
        arr[count].pos.y = initialY - 2;
        arr[count].numOfMoves = findNumMoves(board, initialX + 1, initialY - 2, dimension);
        ++count;
    }
    if(initialX - 2 >= 0 && initialY - 1 >= 0  && !board[initialX - 2][initialY - 1])
    {
        arr[count].pos.x = initialX - 2;
        arr[count].pos.y = initialY - 1;
        arr[count].numOfMoves = findNumMoves(board, initialX - 2, initialY - 1, dimension);
        ++count;
    }
    if(initialX - 1 >= 0 && initialY - 2 >= 0  && !board[initialX - 1][initialY - 2])
    {
        arr[count].pos.x = initialX - 1;
        arr[count].pos.y = initialY - 2;
        arr[count].numOfMoves = findNumMoves(board, initialX - 1, initialY - 2, dimension);
        ++count;
    }
    if(initialX - 2 >= 0 && initialY + 1 < dimension  && !board[initialX - 2][initialY + 1])
    {
        arr[count].pos.x = initialX - 2;
        arr[count].pos.y = initialY + 1;
        arr[count].numOfMoves = findNumMoves(board, initialX - 2, initialY + 1, dimension);
        ++count;
    }
    if(initialX - 1 >= 0 && initialY + 2 < dimension  && !board[initialX - 1][initialY + 2])
    {
        arr[count].pos.x = initialX - 1;
        arr[count].pos.y = initialY + 2;
        arr[count].numOfMoves = findNumMoves(board, initialX - 1, initialY + 2, dimension);
        ++count;
    }

    return arr;
}