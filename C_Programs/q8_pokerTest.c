#include <stdio.h>
#include <string.h>

void analyze(int num[], int n, int *counts)
{
    int freq[10] = {0};
    int pair = 0, triple = 0, four = 0;

    // Count frequency and categorize in one pass
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= 0 && num[i] <= 9)
        {
            freq[num[i]]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] == 4) four++;
        else if (freq[i] == 3) triple++;
        else if (freq[i] == 2) pair++;
    }

    // Classify into appropriate category
    if (four) counts[4]++;
    else if (triple) counts[3]++;
    else if (pair == 2) counts[2]++;
    else if (pair == 1) counts[1]++;
    else counts[0]++;
}

int main()
{
    int n, digits;
    int counts[5] = {0}; // all_diff, one_pair, two_pairs, three_kind, four_kind

    printf("Enter number of random numbers: ");
    scanf("%d", &n);

    printf("Enter number of digits (3 or 4): ");
    scanf("%d", &digits);

    if (digits != 3 && digits != 4)
    {
        printf("Invalid digit size. Only 3 or 4 allowed.\n");
        return 0;
    }

    int num[4];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter %d digits (0-9): ", digits);
        for (int j = 0; j < digits; j++)
            scanf("%d", &num[j]);

        analyze(num, digits, counts);
    }

    printf("\n--- Poker Test Results ---\n");
    printf("All Different   : %d\n", counts[0]);
    printf("One Pair        : %d\n", counts[1]);

    if (digits == 4)
    {
        printf("Two Pairs       : %d\n", counts[2]);
        printf("Three of a Kind : %d\n", counts[3]);
        printf("Four of a Kind  : %d\n", counts[4]);
    }
    else
    {
        printf("Three of a Kind : %d\n", counts[3]);
    }

    return 0;
}
