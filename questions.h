/* questions.h - Question Handling */
#ifndef QUESTIONS_H
#define QUESTIONS_H

typedef struct {
    char category[50];
    char question[100];
    char answer[50];
    int value;
    int answered;
} question;

void initialize_game();
void display_categories();
void display_question(char *category, int value);
int valid_answer(char *category, int value, char *answer);
int already_answered(char *category, int value);
const char* get_correct_answer(char *category, int value);

#endif