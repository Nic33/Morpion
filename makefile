CFLAGS= -Wall -g -std=c99

all : game

game  : game.o game_print.o game_save.o

rm:
	rm -f *.o game *.txt

.PHONY: all