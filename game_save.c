#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "game_save.h"

void game_save(game g, char *filename){
    FILE *f;

    f = fopen(filename, "w");
    fprintf(f,"%d %d", g->sizeX, g->sizeY);
    fprintf(f, "\n");

    for (int i = 0; i < g->sizeX; i++){
        for (int j = 0; j < g->sizeY; j++){
            if (g->squares[i * g->sizeY +j] == BLANK){
                fprintf(f,"_");

            }
            if (g->squares[i * g->sizeY +j] == CROSS){
                fprintf(f,"X");

            }
            if (g->squares[i * g->sizeY +j] == CIRCLE){
                fprintf(f,"O");

            }
        }
        fprintf(f, "\n");

    }
    fclose(f);

}
game game_load(char *filename){
    FILE *f;
    f = fopen(filename, "r");

    int x, y;
    char c;
    fscanf(f, "%d %d\n", &x, &y);
    game g = new_game(x,y);

    for (int i = 0; i < g->sizeX; i++){
        for (int j = 0; j < g->sizeY; j++){
            fscanf(f,"%c ", &c);
            if (c == '_'){
                g->squares[i *g->sizeY +j] = BLANK;
            }
            if (c == 'O'){
                g->squares[i *g->sizeY +j] = CIRCLE;
            }
            if (c == 'X'){
                g->squares[i *g->sizeY +j] = CROSS;
            }
        }
    }
    return g;
}
