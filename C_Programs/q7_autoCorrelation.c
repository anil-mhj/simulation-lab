// c program to implement auto-correlation test
#include <stdio.h>

#define MAX 100

int main()
{
    int n, i, k;
    double data[MAX], mean = 0.0;
    double numerator = 0.0, denominator = 0.0;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the data values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &data[i]);
        mean += data[i];
    }

    mean /= n;

    printf("Enter lag (k): ");
    scanf("%d", &k);

    if (k >= n || k < 0)
    {
        printf("Invalid lag.\n");
        return 1;
    }

    // numerator
    for (i = 0; i < n - k; i++)
    {
        numerator += (data[i] - mean) * (data[i + k] - mean);
    }

    // denominator
    for (i = 0; i < n; i++)
    {
        denominator += (data[i] - mean) * (data[i] - mean);
    }

    double autocorr = numerator / denominator;

    printf("Autocorrelation at lag %d = %lf\n", k, autocorr);

    return 0;
}