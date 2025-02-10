/* questions.c - Manages questions */
#include <stdio.h>
#include <string.h>
#include "questions.h"
#include "players.h"

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

int game_over() {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return 0; // Game is not over if any question is unanswered
        }
    }
    return 1; // Game is over if all questions are answered
}