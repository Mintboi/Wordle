//
// Created by Swift on 21/02/2023.
//

#include "validation.h"

int Length(char c[]) {
    int len = 0;
    while (c[len] != '\0') {
        len++;
    }
    return len;
}

int is_in_array(char c, char guess[], int length) {
        for (int i = 0; i < length; i++) {
            if (c == guess[i]) {
                return 1; // char is in array
            }
        }
        return 0; // char is not in array
    }


    /// Insanely Slow, needs work
int is_word_in_dict(char* word, char dictionary[DICT_SIZE][WORD_SIZE+1]) {
    int i, j, k, match;
    for (i = 0; i < DICT_SIZE; i++) {
        match = 1;
        for (j = 0, k = 0; j < WORD_SIZE && k < Length(word); j++, k++) {
            if (dictionary[i][j] != word[k]) {
                match = 0;
                break;
            }
        }
        if (match && k == Length(word)) {
            return 1;
        }
    }
    return 0;
}
