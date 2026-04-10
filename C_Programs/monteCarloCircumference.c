#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, inside = 0;
    double x, y, pi, radius, circumference;

    printf("Enter number of random points: ");
    scanf("%d", &n);

    printf("Enter radius of circle: ");
    scanf("%lf", &radius);

    srand(time(0));

    for(i = 0; i < n; i++) {
        // Generate random point between -1 and 1
        x = (double)rand()/RAND_MAX * 2 - 1;
        y = (double)rand()/RAND_MAX * 2 - 1;

        // Check if inside unit circle
        if(x*x + y*y <= 1)
            inside++;
    }

    // Estimate pi
    pi = 4.0 * inside / n;

    // Calculate circumference
    circumference = 2 * pi * radius;

    printf("\nEstimated Pi = %lf\n", pi);
    printf("Estimated Circumference = %lf\n", circumference);

    return 0;
}