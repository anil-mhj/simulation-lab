// Write a C program to simulate games of dice that generate discrete random variate,
// using random number generation.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SUM 12

int rollDie() {
    return 1 + (int)(6.0 * rand() / (RAND_MAX + 1.0));
}

int rollTwoDice() {
    return rollDie() + rollDie();
}

void printFrequency(int freq[], int start, int end) {
    printf("\n=== Frequency Distribution ===\n");
    printf("Outcome   Frequency   Probability\n");
    printf("----------------------------------\n");

    int total = 0;
    for (int i = start; i <= end; i++) {
        total += freq[i];
    }

    for (int i = start; i <= end; i++) {
        double prob = (total > 0) ? (freq[i] * 100.0 / total) : 0.0;
        printf("%3d %12d %12.2f%%\n", i, freq[i], prob);
    }
}

int main() {
    srand((unsigned int)time(NULL));

    int choice, numRolls;

    printf("=== Dice Simulation ===\n");
    printf("1. Single Die\n");
    printf("2. Two Dice\n");

    printf("Choice (1-2): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Number of rolls: ");
    if (scanf("%d", &numRolls) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (numRolls <= 0) {
        printf("Invalid number of rolls!\n");
        return 1;
    }

    int *freq = calloc(MAX_SUM + 1, sizeof(int));
    if (!freq) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int start = 0, end = 0;

    switch (choice) {
        case 1:
            start = 1;
            end = 6;
            for (int i = 0; i < numRolls; i++) {
                freq[rollDie()]++;
            }
            break;

        case 2:
            start = 2;
            end = 12;
            for (int i = 0; i < numRolls; i++) {
                freq[rollTwoDice()]++;
            }
            break;

        default:
            printf("Invalid choice!\n");
            free(freq);
            return 1;
    }

    printFrequency(freq, start, end);

    double mean = 0.0;
    for (int i = start; i <= end; i++) {
        mean += i * freq[i];
    }
    mean /= numRolls;

    printf("\nTheoretical Mean: %.1f\n", (choice == 1) ? 3.5 : 7.0);
    printf("Observed Mean   : %.3f\n", mean);

    free(freq);
    return 0;
}