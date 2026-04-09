#include <stdio.h>
#include <string.h>

// Function to sort array (Bubble Sort)
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search element (Linear Search)
void searchArray(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

// Function for string concatenation
void concatStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

// Function for string comparison
void compareStrings(char str1[], char str2[]) {
    int result = strcmp(str1, str2);
    if (result == 0)
        printf("Strings are equal.\n");
    else if (result < 0)
        printf("String 1 is smaller than String 2.\n");
    else
        printf("String 1 is greater than String 2.\n");
}

int main() {
    int choice, subChoice;

    printf("Select Category:\n");
    printf("1. Array Operations\n");
    printf("2. String Operations\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    switch (choice) {

        case 1: {
            int n, arr[100], key;

            printf("\nArray Operations:\n");
            printf("1. Sorting\n");
            printf("2. Searching\n");
            printf("Enter your choice: ");
            scanf("%d", &subChoice);

            printf("Enter number of elements: ");
            scanf("%d", &n);

            if (n <= 0 || n > 100) {
                printf("Invalid array size!\n");
                return 1;
            }

            printf("Enter elements:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            if (subChoice == 1) {
                sortArray(arr, n);
            } else if (subChoice == 2) {
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchArray(arr, n, key);
            } else {
                printf("Invalid choice!\n");
            }
            break;
        }

        case 2: {
            char str1[100], str2[100];

            printf("\nString Operations:\n");
            printf("1. Concatenation\n");
            printf("2. Comparison\n");
            printf("Enter your choice: ");
            scanf("%d", &subChoice);

            printf("Enter first string: ");
            scanf("%s", str1);

            printf("Enter second string: ");
            scanf("%s", str2);

            if (subChoice == 1) {
                concatStrings(str1, str2);
            } else if (subChoice == 2) {
                compareStrings(str1, str2);
            } else {
                printf("Invalid choice!\n");
            }
            break;
        }

        default:
            printf("Invalid main choice!\n");
    }

    return 0;
}
