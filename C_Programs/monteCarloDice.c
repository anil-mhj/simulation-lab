#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n;
    int count[7] = {0};  // index 1–6 used
    int roll;
    double average = 0;

    printf("Enter number of simulations: ");
    scanf("%d", &n);

    // Seed random number generator
    srand(time(0));

    // Monte Carlo Simulation
    for(i = 0; i < n; i++) {
        roll = rand() % 6 + 1;  // generates 1 to 6
        count[roll]++;
        average += roll;
    }

    // Output results
    printf("\nResults after %d simulations:\n", n);
    for(i = 1; i <= 6; i++) {
        printf("Face %d occurred %d times (Probability = %.4f)\n",
               i, count[i], (double)count[i]/n);
    }

    printf("\nAverage value = %.4f\n", average/n);

    return 0;
}