#include <stdio.h>

int main() {
    int classes, students, subjects, marks;
    int c, s, sub;
    int total, classTotal, schoolTotal = 0;
    int studentCount, schoolStudents = 0;
    float avg, classAvgSum, schoolAvgSum = 0;
    int failed;

    printf("Enter the number of classes: ");
    scanf("%d", &classes);

    for (c = 1; c <= classes; c++) {
        classTotal = 0;
        classAvgSum = 0;

        printf("\nEnter the number of students in Class %d: ", c);
        scanf("%d", &students);
        studentCount = students;

        for (s = 1; s <= students; s++) {
            total = 0;
            failed = 0;

            printf("Enter the number of subjects for Student %d: ", s);
            scanf("%d", &subjects);

            for (sub = 1; sub <= subjects; sub++) {
                printf("  Marks in subject %d: ", sub);
                scanf("%d", &marks);

                total += marks;
                if (marks < 40) {
                    failed = 1;
                }
            }

            avg = (float) total / subjects;

            printf("Class %d, Student %d: Total Marks = %d, Average = %.2f, Result = %s\n",
                   c, s, total, avg, failed ? "Fail" : "Pass");

            classTotal += total;
            classAvgSum += avg;
        }

        // class average = average of the students' averages
        printf("\nClass %d total marks: %d\n", c, classTotal);
        printf("Class %d average: %.2f\n", c, classAvgSum / studentCount);

        schoolTotal += classTotal;
        schoolAvgSum += classAvgSum;
        schoolStudents += studentCount;
    }

    printf("\nTotal marks of all students in the school: %d\n", schoolTotal);
    printf("Overall school average: %.2f\n", schoolAvgSum / schoolStudents);

    return 0;
}