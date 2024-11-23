#include <stdio.h>
#include <string.h>

// Define the Student structure
typedef struct {
    char name[50];
    int age;
    float marks;
} Student;

// Function to input details for all students
void input_students(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Use %[^\n] to read strings with spaces
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

// Function to display details of all students
void display_students(Student students[], int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Name: %s, Age: %d, Marks: %.2f\n", 
                i + 1, students[i].name, students[i].age, students[i].marks);
    }
}

// Function to sort students based on marks in descending order
void sort_students_by_marks(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap students[j] and students[j + 1]
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to find the student with the highest marks
Student find_highest_marks(Student students[], int n) {
    Student top_student = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].marks > top_student.marks) {
            top_student = students[i];
        }
    }
    return top_student;
}

// Main function
int main() {
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Create an array of Student structures
    Student students[n];

    // Input student details
    input_students(students, n);

    // Display all student details
    display_students(students, n);

    // Sort students by marks
    sort_students_by_marks(students, n);

    // Display sorted list
    printf("\nStudents sorted by marks (Descending Order):\n");
    display_students(students, n);

    // Find and display the student with the highest marks
    Student top_student = find_highest_marks(students, n);
    printf("\nStudent with the highest marks:\n");
    printf("Name: %s, Age: %d, Marks: %.2f\n", 
            top_student.name, top_student.age, top_student.marks);

    return 0;
}
