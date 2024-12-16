#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    struct Task* next;
    struct Task* prev;
};

struct Task* head = NULL;

// Function to create a new task node
struct Task* createTask(char description[]) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    strcpy(newTask->description, description);
    newTask->next = NULL;
    newTask->prev = NULL;
    return newTask;
}

// Add task at the beginning
void addTaskAtBeginning(char description[]) {
    struct Task* newTask = createTask(description);
    if (head != NULL) {
        newTask->next = head;
        head->prev = newTask;
    }
    head = newTask;
    printf("Task added to the beginning: %s\n", description);
}

// Add task at the end
void addTaskAtEnd(char description[]) {
    struct Task* newTask = createTask(description);
    if (head == NULL) {
        head = newTask;
    } else {
        struct Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
        newTask->prev = temp;
    }
    printf("Task added to the end: %s\n", description);
}

// Delete task from the beginning
void deleteTaskFromBeginning() {
    if (head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }
    struct Task* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Task deleted from the beginning: %s\n", temp->description);
    free(temp);
}

// Delete task from the end
void deleteTaskFromEnd() {
    if (head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Task deleted from the end: %s\n", head->description);
        free(head);
        head = NULL;
        return;
    }
    struct Task* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Task deleted from the end: %s\n", temp->description);
    free(temp);
}

// Display all tasks
void displayTasks() {
    if (head == NULL) {
        printf("No tasks in the list.\n");
        return;
    }
    struct Task* temp = head;
    printf("Current To-Do List:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->description);
        temp = temp->next;
    }
}

// Main function to demonstrate the To-Do List application
int main() {
    int choice;
    char description[100];

    while (1) {
        printf("\nTo-Do List Options:\n");
        printf("1. Add task at beginning\n");
        printf("2. Add task at end\n");
        printf("3. Delete task from beginning\n");
        printf("4. Delete task from end\n");
        printf("5. Display all tasks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = '\0';  
                addTaskAtBeginning(description);
                break;
            case 2:
                printf("Enter task description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = '\0';
                addTaskAtEnd(description);
                break;
            case 3:
                deleteTaskFromBeginning();
                break;
            case 4:
                deleteTaskFromEnd();
                break;
            case 5:
                displayTasks();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
