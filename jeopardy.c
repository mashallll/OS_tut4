/* jeopardy.c - Enhanced Interactive Jeopardy Game */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "questions.h"
#include "players.h"

#define MAX_PLAYERS 4

void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape sequence to clear the screen
}

void welcome_screen() {
    clear_screen();
    printf("========================================\n");
    printf("         WELCOME TO JEOPARDY!           \n");
    printf("========================================\n");
    printf("\nPress Enter to Start...");
    getchar();
}

void print_scoreboard(player players[]) {
    clear_screen();
    printf("========================================\n");
    printf("          SCOREBOARD                    \n");
    printf("========================================\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
    printf("========================================\n");
}

int main() {
    player players[MAX_PLAYERS];
    initialize_game();

    welcome_screen();
    
    // Get player names
    printf("Enter names of 4 players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%49s", players[i].name);
        players[i].score = 0;
    }

    // Game loop
    char category[50];
    int value;
    char answer[100];
    while (!game_over()) {
        print_scoreboard(players);
        display_categories();
        printf("\n%s, Choose a category and value (e.g., Science 200): ", players[0].name);
        scanf("%49s %d", category, &value);
        
        if (already_answered(category, value)) {
            printf("That question has already been answered. Try again!\n");
            continue;
        }
        
        display_question(category, value);
        printf("Enter your answer (e.g., 'What is oxygen?'): ");
        getchar();  // Clear newline
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;  // Remove newline
        
        if (valid_answer(category, value, answer)) {
            printf("Correct! You earn $%d\n", value);
            update_score(players, players[0].name, value);
        } else {
            printf("Incorrect! The correct answer was: %s\n", get_correct_answer(category, value));
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    print_scoreboard(players);
    printf("\nGame Over!\n");
    show_results(players);
    return 0;
}
