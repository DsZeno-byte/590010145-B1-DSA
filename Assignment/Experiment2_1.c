#include <stdio.h>
#include <string.h>

// Define a structure for employee information
struct EmployeeStruct {
    char name[50];
    int employeeID;
    float salary;
};

// Define a union for employee information
union EmployeeUnion {
    char name[50];
    int employeeID;
    float salary;
};

int main() {
    // Initialize and display values stored in structure
    struct EmployeeStruct empStruct;
    strcpy(empStruct.name, "Alice");
    empStruct.employeeID = 101;
    empStruct.salary = 50000.00;

    printf("Employee Information using Structure:\n");
    printf("Name: %s\n", empStruct.name);
    printf("Employee ID: %d\n", empStruct.employeeID);
    printf("Salary: %.2f\n", empStruct.salary);

    // Initialize and display values stored in union
    union EmployeeUnion empUnion;
    strcpy(empUnion.name, "Bob");
    printf("\nEmployee Information using Union:\n");
    printf("Name: %s\n", empUnion.name);

    empUnion.employeeID = 102;
    printf("Employee ID: %d\n", empUnion.employeeID);

    empUnion.salary = 60000.00;
    printf("Salary: %.2f\n", empUnion.salary);

    // Display memory size of structure and union
    printf("\nMemory Size:\n");
    printf("Size of Structure: %lu bytes\n", sizeof(empStruct));
    printf("Size of Union: %lu bytes\n", sizeof(empUnion));

    return 0;
}
