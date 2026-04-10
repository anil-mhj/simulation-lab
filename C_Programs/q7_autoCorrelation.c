// c program to implement auto-correlation test
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j;
    double sum = 0.0, mean = 0.0, auto_corr = 0.0;

    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    double random_numbers[100];
    printf("Enter the random numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &random_numbers[i]);
        mean += random_numbers[i];
    }

    mean /= n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += (random_numbers[i] - mean) * (random_numbers[j] - mean);
        }
    }

    auto_corr = sum / (n * n);
    printf("Auto-correlation: %.2lf\n", auto_corr);

    return 0;
}