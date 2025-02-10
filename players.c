/* players.c - Manages players */
#include <stdio.h>
#include <string.h>
#include "players.h"

void update_score(player *players, char *name, int score) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
        }
    }
}

void show_results(player *players) {
    printf("Final Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}