#include <stdlib.h>
#include "moves.h"

//Assumed that board is filled with 0s
void fillBoard(byte** board, byte initialX, byte initialY, byte dimension);

void fill(byte** board, byte initialX, byte initialY, byte dimension, byte level);

move* getValidMoves(byte** board, byte initialX, byte initialY, byte size, byte dimension);

byte findNumMoves(byte** board, byte initialX, byte initialY, byte dimension);