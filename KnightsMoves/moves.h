
typedef unsigned char byte;

typedef struct pair_t
{
    byte x;
    byte y;
} position;

typedef struct move_t
{
    position pos;
    byte numOfMoves;
} move;
