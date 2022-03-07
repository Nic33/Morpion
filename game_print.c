#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "game_print.h"

void game_print(game g){

    printf("  ");
    for (int i = 0; i < g->sizeX; i++){
        printf("%d", i);
    }
    printf("\n");
    printf("  ");

    for (int i = 0; i < g->sizeX; i++){
        printf("-");
    }printf("\n");

    for (int i = 0; i < g->sizeY; i++){
        printf("%d|",i);
        for (int j = 0; j < g->sizeX; j++){
            if (g->squares[i * g->sizeX + j] == BLANK){
                printf(" ");
            }
            if (g->squares[i * g->sizeX + j] == CROSS){
                printf("X");
            }
            if (g->squares[i * g->sizeX + j] == CIRCLE){
                printf("O");
            }
        }
        printf("|\n");
    }
    printf("  ");
    for (int i = 0; i < g->sizeX; i++){
        printf("-");
    }printf("\n");
    
}

void game_add(game g, square s , int posX, int posY){
    
    g->squares[posX * g->sizeY + posY] = s;

}

