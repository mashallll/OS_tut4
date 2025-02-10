#ifndef PLAYERS_H
#define PLAYERS_H

#define MAX_PLAYERS 4  // Move MAX_PLAYERS here for global use

typedef struct {
    char name[50];
    int score;
} player;

void update_score(player *players, char *name, int score);
void show_results(player *players);

#endif
