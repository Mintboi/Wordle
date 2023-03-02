#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.c"
#include "play.c"
#include "Histogram.c"

#define DICT_SIZE 5757
#define WORD_SIZE 5

int main() {
    char playGame = 'y';
    int numGames = 0;
    int numWins = 0;
    while(playGame == 'y' || playGame == 'Y'){
        srand(time(NULL));
        char dictionary[DICT_SIZE][WORD_SIZE + 1];
        load_word_list(dictionary);
        int random_index = rand() % DICT_SIZE; // choose a random word from the dictionary
        char selected_word[WORD_SIZE + 1];

        for(int i = 0; i< WORD_SIZE; i++){// copy the chosen word to a new array
            selected_word[i] = dictionary[random_index][i];
        }
        printf("%s \n", selected_word);
        numWins += play(selected_word, dictionary);
        numGames++;
        printf("Would you like to play again? (y/n) ");
        playGame = getchar();
    }
    printf("%d Percent win-rate", calculate_win_rate(numWins,numGames));
    print_histogram();
    return 0;
}


