// c program to implement chi square test
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double observed[100], expected[100], chi_square = 0.0;

    printf("Enter the number of categories: ");
    scanf("%d", &n);

    printf("Enter the observed frequencies:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &observed[i]);
    }

    printf("Enter the expected frequencies:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &expected[i]);
    }

    for (i = 0; i < n; i++)
    {
        chi_square += pow(observed[i] - expected[i], 2) / expected[i];
    }

    printf("Chi-Square Statistic: %.2lf\n", chi_square);

    return 0;
}