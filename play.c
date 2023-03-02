//
// Created by Swift on 21/02/2023.
//
#include <stdio.h>
#include "validation.c"
#include "play.h"

#define DICT_SIZE 5757
#define WORD_SIZE 5
#define MAX_GUESSES 6

// Main Game Loop
// takes the randomly selected word and compares it to user guesses
int play(char selected_word[], char dictionary[DICT_SIZE][WORD_SIZE + 1]) {
    char guess[WORD_SIZE + 1];
    int num_guesses = 0;

    //Loop stops user from having more than 6 guesses
    while (num_guesses <= MAX_GUESSES) {
        printf("Guess a 5-letter word (guess %d of %d): ", num_guesses + 1, MAX_GUESSES);

        int iterator = 0;
        char c;
        while ((c = getchar()) != '\n') {
            guess[iterator] = c;
            iterator++;
        }
        guess[iterator] = '\0'; // Add null terminator

        while (!is_word_in_dict(guess, dictionary)) {
            printf("Please input a real 5-letter word: ");
             iterator = 0;
            while ((c = getchar()) != '\n') {
                guess[iterator] = c;
                iterator++;
            }
            guess[iterator] = '\0';
        }

        while (Length(guess) != WORD_SIZE) {
            printf("Please input a 5-letter word: ");
            iterator = 0;
            while ((c = getchar()) != '\n') {
                guess[iterator] = c;
                iterator++;
            }
            guess[iterator] = '\0'; // Add null terminator
        }

        int num_correct = 0;
        char correct_letters[WORD_SIZE + 1] = {0}; // Initialize array to 0
        for (int i = 0; i < WORD_SIZE; i++) {
            if (guess[i] == selected_word[i]) {
                printf("%c", guess[i]);
                correct_letters[i] = guess[i];
                num_correct++;
            } else if (is_in_array(guess[i], selected_word, WORD_SIZE)) {
                printf("-");
            } else {
                printf("%c", '-');
            }
        }
        printf("\n");
        printf("Correct Letters: ");
        for (int i = 0; i < WORD_SIZE; ++i)
            printf(" %c", correct_letters[i]);
        printf("\n");

        if (num_correct == WORD_SIZE) {
            printf("Congratulations, you guessed the word!\n");
            return 1;
        }else if(num_guesses == MAX_GUESSES){
            printf("Sorry, you have run out of guesses. The word was %s.\n", selected_word);
            return 0;
        }
        num_guesses++;
    }

}