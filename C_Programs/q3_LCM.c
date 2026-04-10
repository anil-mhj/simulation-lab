// c program to generate the random numbers using linear congruential generator method
#include <stdio.h>

int main()
{
    long long x0, a, c, m;
    int n;

    printf("Enter the seed value (x0): ");
    scanf("%lld", &x0);

    printf("Enter the multiplier (a): ");
    scanf("%lld", &a);

    printf("Enter the increment (c): ");
    scanf("%lld", &c);

    printf("Enter the modulus (m): ");
    scanf("%lld", &m);

    if (m <= 0)
    {
        printf("Modulus must be greater than 0\n");
        return 1;
    }

    printf("How many random numbers to generate? ");
    scanf("%d", &n);

    printf("Generated random numbers:\n");

    for (int i = 0; i < n; i++)
    {
        x0 = (a * x0 + c) % m;
        float r = (float)x0 / m;
        printf("%f\n", r);
    }

    return 0;
}