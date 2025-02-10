/* jeopardy.c - Main program */
#include <stdio.h>
#include <string.h>
#include "questions.h"
#include "players.h"

#define MAX_PLAYERS 4

int main() {
    player players[MAX_PLAYERS];
    initialize_game();

    // Get player names
    printf("Enter names of 4 players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Game loop
    char category[50];
    int value;
    char answer[100];
    while (!game_over()) {
        display_categories();
        printf("\nChoose a category and value (e.g., Science 200): ");
        scanf("%s %d", category, &value);
        
        if (already_answered(category, value)) {
            printf("That question has already been answered. Try again!\n");
            continue;
        }
        
        display_question(category, value);
        printf("Enter your answer: ");
        scanf(" %[^"]s", answer);
        
        if (valid_answer(category, value, answer)) {
            printf("Correct! You earn $%d\n", value);
            update_score(players, answer, value);
        } else {
            printf("Incorrect! The correct answer was: %s\n", get_correct_answer(category, value));
        }
    }

    show_results(players);
    return 0;
}