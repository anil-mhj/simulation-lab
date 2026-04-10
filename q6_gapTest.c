// c program to implement gap test
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, count = 0;
    double gap, mean_gap = 0.0;

    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    double random_numbers[100];
    printf("Enter the random numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &random_numbers[i]);
    }

    printf("Enter the gap value: ");
    scanf("%lf", &gap);

    for (i = 1; i < n; i++)
    {
        if (fabs(random_numbers[i] - random_numbers[i - 1]) < gap)
        {
            count++;
        }
    }

    mean_gap = (double)count / (n - 1);
    printf("Mean Gap: %.2lf\n", mean_gap);

    return 0;
}