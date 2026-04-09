#include <stdio.h>
#include <limits.h>

// Function for iterative factorial
long long int factorialIterative(int n) {
    long long int fact = 1;
    for (int i = 1; i <= n; i++) {
        if (fact > LLONG_MAX / i) {  // Overflow check
            return -1;
        }
        fact *= i;
    }
    return fact;
}

// Function for recursive factorial
long long int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;

    long long int result = factorialRecursive(n - 1);

    // Overflow check
    if (result == -1 || result > LLONG_MAX / n)
        return -1;

    return n * result;
}

int main() {
    int num, choice;
    long long int result;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        return 1;
    }

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    printf("\nChoose method:\n");
    printf("1. Iterative\n");
    printf("2. Recursive\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = factorialIterative(num);
            break;

        case 2:
            result = factorialRecursive(num);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    if (result == -1) {
        printf("Error: Overflow occurred! Number too large.\n");
    } else {
        printf("Factorial of %d is: %lld\n", num, result);
    }

    return 0;
}
