/* questions.c - Manages questions */
#include <stdio.h>
#include <string.h>
#include "questions.h"
#include "players.h"

#define TOTAL_QUESTIONS 12

question questions[TOTAL_QUESTIONS];

void initialize_game() {
    // Science Category
    strcpy(questions[0].category, "Science");
    strcpy(questions[0].question, "What is the chemical symbol for water?");
    strcpy(questions[0].answer, "H2O");
    questions[0].value = 200;
    questions[0].answered = 0;

    strcpy(questions[1].category, "Science");
    strcpy(questions[1].question, "What planet is known as the Red Planet?");
    strcpy(questions[1].answer, "Mars");
    questions[1].value = 400;
    questions[1].answered = 0;

    // History Category
    strcpy(questions[2].category, "History");
    strcpy(questions[2].question, "Who was the first President of the United States?");
    strcpy(questions[2].answer, "George Washington");
    questions[2].value = 200;
    questions[2].answered = 0;

    strcpy(questions[3].category, "History");
    strcpy(questions[3].question, "In which year did World War II end?");
    strcpy(questions[3].answer, "1945");
    questions[3].value = 400;
    questions[3].answered = 0;

    // Geography Category
    strcpy(questions[4].category, "Geography");
    strcpy(questions[4].question, "What is the capital of France?");
    strcpy(questions[4].answer, "Paris");
    questions[4].value = 200;
    questions[4].answered = 0;

    strcpy(questions[5].category, "Geography");
    strcpy(questions[5].question, "Which is the longest river in the world?");
    strcpy(questions[5].answer, "Nile");
    questions[5].value = 400;
    questions[5].answered = 0;

    // Sports Category
    strcpy(questions[6].category, "Sports");
    strcpy(questions[6].question, "How many players are there in a soccer team?");
    strcpy(questions[6].answer, "11");
    questions[6].value = 200;
    questions[6].answered = 0;

    strcpy(questions[7].category, "Sports");
    strcpy(questions[7].question, "Which country won the FIFA World Cup in 2018?");
    strcpy(questions[7].answer, "France");
    questions[7].value = 400;
    questions[7].answered = 0;

    // Technology Category
    strcpy(questions[8].category, "Technology");
    strcpy(questions[8].question, "Who is the founder of Microsoft?");
    strcpy(questions[8].answer, "Bill Gates");
    questions[8].value = 200;
    questions[8].answered = 0;

    strcpy(questions[9].category, "Technology");
    strcpy(questions[9].question, "What does 'CPU' stand for?");
    strcpy(questions[9].answer, "Central Processing Unit");
    questions[9].value = 400;
    questions[9].answered = 0;
}

void display_categories() {
    printf("Available Categories:\n");
    printf("Science - 200, 400\n");
    printf("History - 200, 400\n");
    printf("Geography - 200, 400\n");
    printf("Sports - 200, 400\n");
    printf("Technology - 200, 400\n");
}

void display_question(char *category, int value) {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("No question found for this category and value.\n");
}

int valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return strcmp(answer, questions[i].answer) == 0;
        }
    }
    return 0;
}

int already_answered(char *category, int value) {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return 0;
}

const char* get_correct_answer(char *category, int value) {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answer;
        }
    }
    return "No answer available";
}

int game_over() {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return 0; // Game is not over if any question is unanswered
        }
    }
    return 1; // Game is over if all questions are answered
}
