#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, i, count = 0;
    double x, y, r, radius, thickness;
    double circumference;

    printf("Enter number of random points: ");
    scanf("%d", &n);

    printf("Enter radius of circle: ");
    scanf("%lf", &radius);

    printf("Enter thickness (small value like 0.01): ");
    scanf("%lf", &thickness);

    if (n <= 0 || radius <= 0 || thickness <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i++) {
        // Generate random point in square [-r, r]
        x = ((double)rand() / RAND_MAX) * 2 * radius - radius;
        y = ((double)rand() / RAND_MAX) * 2 * radius - radius;

        r = sqrt(x*x + y*y);

        // Check if point lies in thin ring near boundary
        if (r >= radius - thickness && r <= radius)
            count++;
    }

    // Area of square = (2r)^2 = 4r^2
    double square_area = 4 * radius * radius;

    // Estimate circumference
    circumference = (double)count / n * square_area / thickness;

    printf("\nEstimated Circumference = %lf\n", circumference);
    printf("Actual Circumference    = %lf\n", 2 * M_PI * radius);

    return 0;
}