#include <stdio.h>

int main() {
    int n, i, key;
    int arr[100];

    printf("Enter number of elements in sequence: ");
    scanf("%d", &n);

    printf("Enter the sequence (0-9 numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the digit to test (0-9): ");
    scanf("%d", &key);

    int last_index = -1;
    int gap_count = 0;

    printf("\nGaps between occurrences of %d:\n", key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (last_index != -1) {
                printf("Gap %d: %d\n", gap_count + 1, i - last_index - 1);
                gap_count++;
            }
            last_index = i;
        }
    }

    if (gap_count == 0) {
        printf("Not enough occurrences of %d to compute gaps.\n", key);
    }

    return 0;
}