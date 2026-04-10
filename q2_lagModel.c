// Write a C program to find the growth in national consumption for five years
// using Distributed Lag Model given below:
// I = 2 + 0.1 Y1
// Y = 45.45 + 2.27 (I +G)
// T = 0.2 Y
// C = 20 + 0.7 (YT)
// Assume the initial value of Y1 is 80 and take the governmental expenditure in the 5
// years to be as follows:
// Year G
// 1 20
// 2 25
// 3 30
// 4 35
// 5 40
#include <stdio.h>

int main()
{
    int year;
    double Y1 = 80; // Initial lagged income
    double G[5] = {20, 25, 30, 35, 40};
    double I, Y, T, C;

    printf("Year\tG\tI\tY\tT\tC\n");

    for (year = 0; year < 5; year++)
    {
        // Step 1: Investment
        I = 2 + 0.1 * Y1;

        // Step 2: National income
        Y = 45.45 + 2.27 * (I + G[year]);

        // Step 3: Tax
        T = 0.2 * Y;

        // Step 4: Consumption
        C = 20 + 0.7 * (Y - T);

        // Print results
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", year + 1, G[year], I, Y, T, C);

        // Update Y1 for next year (Distributed Lag)
        Y1 = Y;
    }

    return 0;
}