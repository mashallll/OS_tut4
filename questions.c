/* questions.c - Manages questions */
#include <stdio.h>
#include <string.h>
#include "questions.h"

#define TOTAL_QUESTIONS 12

question questions[TOTAL_QUESTIONS];

void initialize_game() {
    strcpy(questions[0].category, "Science");
    strcpy(questions[0].question, "What is the chemical symbol for water?");
    strcpy(questions[0].answer, "H2O");
    questions[0].value = 200;
    questions[0].answered = 0;
}

void display_categories() {
    printf("Available Categories:\n");
    printf("Science - 200\n");
}

void display_question(char *category, int value) {
    printf("Question: %s\n", questions[0].question);
}

int valid_answer(char *category, int value, char *answer) {
    return strcmp(answer, questions[0].answer) == 0;
}

int already_answered(char *category, int value) {
    return questions[0].answered;
}

const char* get_correct_answer(char *category, int value) {
    return questions[0].answer;
}

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