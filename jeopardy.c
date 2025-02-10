/* jeopardy.c - Main program */
#include <stdio.h>
#include <string.h>
#include "questions.h"
#include "players.h"

int main() {
    player players[MAX_PLAYERS];
    initialize_game();

    // Get player names
    printf("Enter names of 4 players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%49s", players[i].name);  // Limit input to avoid buffer overflow
        players[i].score = 0;
    }

    // Game loop
    char category[50];
    int value;
    char answer[100];
    while (!game_over()) {
        display_categories();
        printf("\nChoose a category and value (e.g., Science 200): ");
        scanf("%49s %d", category, &value); // Limit category input size
        
        if (already_answered(category, value)) {
            printf("That question has already been answered. Try again!\n");
            continue;
        }
        
        display_question(category, value);
        printf("Enter your answer: ");
        scanf(" %99[^']'", answer);  // Fix incorrect format specifier for string
        
        if (valid_answer(category, value, answer)) {
            printf("Correct! You earn $%d\n", value);
            update_score(players, players[0].name, value); // Fix incorrect argument
        } else {
            printf("Incorrect! The correct answer was: %s\n", get_correct_answer(category, value));
        }
    }

    show_results(players);
    return 0;
}
