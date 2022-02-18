#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    CROSS,
    CIRCLE,
    BLANK
}square;

typedef struct game_s{
    int sizeX;
    int sizeY;
    bool over;
    square *squares;
} *game;


game new_game(int x, int y);
void game_delete(game g);
