//
// Created by Swift on 02/03/2023.
//

#include "Histogram.h"


int calculate_win_rate(int num_wins, int num_games) {
    if (num_games == 0) {
        return 0;
    }
    return (int)(((float)num_wins / num_games) * 100);
}


void print_histogram(int guesses[], int num_games) {
    int max_guesses = 0;
    for (int i = 0; i < num_games; i++) {
        if (guesses[i] > max_guesses) {
            max_guesses = guesses[i];
        }
    }

    int histogram[max_guesses + 1]; // Create an array to store the histogram data
    for (int i = 0; i <= max_guesses; i++) {
        histogram[i] = 0;
    }

    // Count the frequency of each number of guesses
    for (int i = 0; i < num_games; i++) {
        histogram[guesses[i]]++;
    }

    // Print the histogram
    printf("Histogram of Number of Guesses:\n");
    for (int i = 1; i <= max_guesses; i++) {
        printf("%d: ", i);
        for (int j = 0; j < histogram[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
