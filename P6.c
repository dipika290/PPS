#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure definition
struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;

// Function to add student
void addStudent() {
    if (count >= MAX) {
        printf("Record is full!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

// Function to search student
void searchStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Record Found:\n");
            printf("Name: %s | Marks: %.2f\n",
                   s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to modify student
void modifyStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to modify: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter new Name: ");
            scanf("%s", s[i].name);

            printf("Enter new Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to delete student
void deleteStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1]; // Shift records
            }
            count--;
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
