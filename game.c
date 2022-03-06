#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "game_print.h"
#include "game_save.h"

game new_game(int x, int y){
    game g = malloc(sizeof(struct game_s));
    if (g == NULL){
        fprintf(stderr, "error malloc");
        exit(EXIT_FAILURE);
    };
    g->sizeX = x;
    g->sizeY = y;
    g->over = false;

    g->squares = malloc((g->sizeX*g->sizeY)*sizeof(square));

    for (int i = 0; i < (g->sizeX * g->sizeY); i++) {  // Remplissage du tableau g->tab avec des S_BLANK (Jeu Vide).
        g->squares[i] = BLANK;
    }
    return g;
}

void game_delete(game g){
    free(g->squares);
    free(g);
}

int main(int argc, char *argv[]) {
    int x, y;
    int posX = 0;
    int posY = 0;
    char c = 'i';

    if (argc > 2) {
    fprintf(stderr, "error too many arguments\n");
    return EXIT_FAILURE;
    }

    if (argc == 2) {
        game g = game_load(argv[1]);
        game_print(g);
        printf("i for more information\n");

        while (g->over == false){

            scanf("%c",&c);
            /*
            if (game_update(g) == false){
                printf("Le jeu est terminé ;-)\n");

            }*/
            if (c == 'i'){
                printf("i -> info\n");
                printf("q -> quit\n");
                printf("n -> new game\n");
                printf("x -> cross\n");
                printf("o -> circle\n");
                printf("s -> save game\n");

                game_print(g);

            }
            if (c == 'q'){
                printf("end of Game\n");
                g->over = true;
            }
            if (c == 'n'){
                printf("new game\n");
                game_delete(g);

                printf("Which size would you like ?\n");
                scanf("%d %d", &x, &y);

                g = new_game(x, y);
                game_print(g);
            }
            if (c == 'x'){
                printf("cross position ? \n");
                scanf("%d %d", &posX, &posY);
                if (posX < g->sizeX && posY < g->sizeY && posX >= 0 && posY >= 0 && g->squares[posX * g->sizeY + posY] == BLANK){
                    game_add(g, CROSS, posX, posY);

                }else{
                    printf("error of position \n");
                }
                game_print(g);

            }
            if (c == 'o'){
                printf("circle position ? \n");
                scanf("%d %d", &posX, &posY);
                if (posX < g->sizeX && posY < g->sizeY && posX >= 0 && posY >= 0 && g->squares[posX * g->sizeY + posY] == BLANK){
                    game_add(g, CIRCLE, posX, posY);

                }else{
                    printf("error of position \n");
                }
                game_print(g);

            }
            if (c == 's'){
                printf("save\n");
                printf("name of file:\n");
                char filename[20];
                scanf("%s", filename);
                game_save(g, filename);
                game_print(g);

            }
            
        }
        
        game_delete(g);

    }
    else{

        printf("Which size would you like ?\n");
        scanf("%d %d", &x, &y);

        game g = new_game(x, y);
        game_print(g);
        printf("i for more information\n");

        while (g->over == false){

            scanf("%c",&c);
            scanf("%c",&c);
            /*
            if (game_update(g) == false){
                printf("Le jeu est terminé ;-)\n");
                
            } */

            if (c == 'i'){
                printf("i -> info\n");
                printf("q -> quit\n");
                printf("n -> new game\n");
                printf("x -> cross\n");
                printf("o -> circle\n");
                printf("s -> save game\n");

                game_print(g);

            }
            if (c == 'q'){
                printf("end of game\n");
                g->over = true;
            }
            if (c == 'n'){
                printf("new game\n");
                game_delete(g);

                printf("Which size would you like ?\n");
                scanf("%d %d", &x, &y);

                g = new_game(x, y);
                game_print(g);
            }
            if (c == 'x'){
                printf("cross position ? \n");
                scanf("%d %d", &posX, &posY);
                if (posX < g->sizeX && posY < g->sizeY && posX >= 0 && posY >= 0 && g->squares[posX * g->sizeY + posY] == BLANK){
                    game_add(g, CROSS, posX, posY);

                }else{
                    printf("error of position \n");
                }
                game_print(g);

            }
            if (c == 'o'){
                printf("circle position ? \n");
                scanf("%d %d", &posX, &posY);
                if (posX < g->sizeX && posY < g->sizeY && posX >= 0 && posY >= 0 && g->squares[posX * g->sizeY + posY] == BLANK){
                    game_add(g, CIRCLE, posX, posY);

                }else{
                    printf("error of position \n");
                }
                game_print(g);

            }
            if (c == 's'){
                printf("save\n");
                printf("name of file:\n");
                char filename[20];
                scanf("%s", filename);
                game_save(g, filename);
                game_print(g);

            }
            
        }

        game_delete(g);
    }
    return 0;
}