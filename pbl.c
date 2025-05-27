#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    struct Student* next;
};

struct Student* head = NULL;

void addStudent(int rollNo, char name[]) {
    struct Student* newNode = (struct Student*) malloc(sizeof(struct Student));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
    printf("Student added successfully.\n");
}

void displayStudents() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s\n", temp->rollNo, temp->name);
        temp = temp->next;
    }
}

void searchStudent(int rollNo) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Student Found: Roll No: %d | Name: %s\n", temp->rollNo, temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll No %d not found.\n", rollNo);
}

void deleteStudent(int rollNo) {
    struct Student *temp = head, *prev = NULL;
    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student with Roll No %d not found.\n", rollNo);
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Student deleted successfully.\n");
}

int main() {
    int choice, rollNo;
    char name[50];

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                addStudent(rollNo, name);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &rollNo);
                searchStudent(rollNo);
                break;
            case 4:
                printf("Enter Roll No to delete: ");
                scanf("%d", &rollNo);
                deleteStudent(rollNo);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
