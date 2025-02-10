/* players.h - Player Handling */
#ifndef PLAYERS_H
#define PLAYERS_H

typedef struct {
    char name[50];
    int score;
} player;

void update_score(player *players, char *name, int score);
void show_results(player *players);

#endif