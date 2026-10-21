#include <stdio.h>

int main() {
    int departments, employees, days;
    int d, e;
    int salary, deptTotal, grandTotal = 0;

    printf("Enter the number of departments: ");
    scanf("%d", &departments);

    for (d = 1; d <= departments; d++) {
        deptTotal = 0;

        printf("\nEnter the number of employees in Department %d: ", d);
        scanf("%d", &employees);

        for (e = 1; e <= employees; e++) {
            printf("Days worked by Employee %d: ", e);
            scanf("%d", &days);

            salary = days * 500;
            if (days > 25) {
                salary += 2000;   // bonus
            }

            printf("Department %d, Employee %d: Days Worked = %d, Salary = Rs. %d\n",
                   d, e, days, salary);

            deptTotal += salary;
        }

        printf("\nTotal salary paid in Department %d: Rs. %d\n", d, deptTotal);
        grandTotal += deptTotal;
    }

    printf("\nTotal salary paid across all departments: Rs. %d\n", grandTotal);
    return 0;
}