#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count frequency of each digit in a number
void countDigits(int num, int digits[], int length) {
    char str[10];
    sprintf(str, "%0*d", length, num);  // Convert to fixed-length string with leading zeros
    
    for (int i = 0; i < 10; i++) digits[i] = 0;
    
    for (int i = 0; i < length; i++) {
        int d = str[i] - '0';
        digits[d]++;
    }
}

// Poker Test for 3-digit numbers
void pokerTest3Digit(int numbers[], int n) {
    int count_AAA = 0;   // All same
    int count_AAB = 0;   // One pair
    int count_ABC = 0;   // All different
    
    printf("\n=== Poker Test for 3-Digit Numbers ===\n");
    
    for (int i = 0; i < n; i++) {
        int digits[10] = {0};
        countDigits(numbers[i], digits, 3);
        
        int max_freq = 0;
        int unique = 0;
        
        for (int j = 0; j < 10; j++) {
            if (digits[j] > 0) {
                unique++;
                if (digits[j] > max_freq) max_freq = digits[j];
            }
        }
        
        if (max_freq == 3) count_AAA++;
        else if (max_freq == 2) count_AAB++;
        else if (unique == 3) count_ABC++;
    }
    
    printf("Total numbers tested : %d\n", n);
    printf("All digits same (AAA) : %d (%.2f%%)\n", count_AAA, (count_AAA * 100.0) / n);
    printf("One pair (AAB)       : %d (%.2f%%)\n", count_AAB, (count_AAB * 100.0) / n);
    printf("All different (ABC)  : %d (%.2f%%)\n", count_ABC, (count_ABC * 100.0) / n);
    
    // Expected probabilities for truly random:
    // AAA: 1/100 = 1%, AAB: 27/100 = 27%, ABC: 72/100 = 72%
}

// Poker Test for 4-digit numbers
void pokerTest4Digit(int numbers[], int n) {
    int count_ABCD = 0;  // All different
    int count_AABC = 0;  // One pair
    int count_AABB = 0;  // Two pairs
    int count_AAABC = 0; // Three of a kind
    int count_AAABB = 0; // Full house
    int count_AAAA = 0;  // Four of a kind
    
    printf("\n=== Poker Test for 4-Digit Numbers ===\n");
    
    for (int i = 0; i < n; i++) {
        int digits[10] = {0};
        countDigits(numbers[i], digits, 4);
        
        int freq_count[5] = {0};  // Index 1 to 4
        
        for (int j = 0; j < 10; j++) {
            if (digits[j] > 0) {
                freq_count[digits[j]]++;
            }
        }
        
        if (freq_count[4] == 1) count_AAAA++;
        else if (freq_count[3] == 1 && freq_count[2] == 1) count_AAABB++;
        else if (freq_count[3] == 1) count_AAABC++;
        else if (freq_count[2] == 2) count_AABB++;
        else if (freq_count[2] == 1) count_AABC++;
        else count_ABCD++;
    }
    
    printf("Total numbers tested : %d\n", n);
    printf("All different (ABCD)     : %d (%.2f%%)\n", count_ABCD, (count_ABCD * 100.0) / n);
    printf("One pair (AABC)          : %d (%.2f%%)\n", count_AABC, (count_AABC * 100.0) / n);
    printf("Two pairs (AABB)         : %d (%.2f%%)\n", count_AABB, (count_AABB * 100.0) / n);
    printf("Three of a kind (AAABC)  : %d (%.2f%%)\n", count_AAABC, (count_AAABC * 100.0) / n);
    printf("Full house (AAABB)       : %d (%.2f%%)\n", count_AAABB, (count_AAABB * 100.0) / n);
    printf("Four of a kind (AAAA)    : %d (%.2f%%)\n", count_AAAA, (count_AAAA * 100.0) / n);
}

int main() {
    int choice, n;
    
    printf("=== Poker Test Implementation ===\n");
    printf("1. Test 3-Digit Numbers\n");
    printf("2. Test 4-Digit Numbers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter number of samples to test: ");
    scanf("%d", &n);
    
    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        
        // Validate range
        if (choice == 1 && (numbers[i] < 0 || numbers[i] > 999)) {
            printf("Warning: Number %d is out of 3-digit range (0-999). It will be treated with leading zeros.\n", numbers[i]);
        }
        if (choice == 2 && (numbers[i] < 0 || numbers[i] > 9999)) {
            printf("Warning: Number %d is out of 4-digit range (0-9999). It will be treated with leading zeros.\n", numbers[i]);
        }
    }
    
    if (choice == 1) {
        pokerTest3Digit(numbers, n);
    } else if (choice == 2) {
        pokerTest4Digit(numbers, n);
    } else {
        printf("Invalid choice!\n");
    }
    
    free(numbers);
    return 0;
}