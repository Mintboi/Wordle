//
// Created by Swift on 21/02/2023.
//

#ifndef ASSIGNMENT_1_VALIDATION_H
#define ASSIGNMENT_1_VALIDATION_H

//checks the length of the array
int length(char str[]);

//finds the character in the array, returns bool
int is_in_array(char c, char arr[], int arr_len);

// a very crude method of checking if the word exists in  the word_list document
int is_in_dict(char* word, char dictionary[DICT_SIZE][WORD_SIZE+1]);
#endif //ASSIGNMENT_1_VALIDATION_H
