#include <stdio.h>

int main() {
    int marks[2][3][3];
    int total[2][3];
    int c, s, sub;
    int topStudent[2];
    int overallClass = 0, overallStudent = 0;

    for (c = 0; c < 2; c++) {
        for (s = 0; s < 3; s++) {
            for (sub = 0; sub < 3; sub++) {
                printf("Class %d, Student %d, Subject %d marks: ", c + 1, s + 1, sub + 1);
                scanf("%d", &marks[c][s][sub]);
            }
        }
    }

    // total marks for every student
    printf("\n--- Total marks ---\n");
    for (c = 0; c < 2; c++) {
        for (s = 0; s < 3; s++) {
            total[c][s] = 0;
            for (sub = 0; sub < 3; sub++) {
                total[c][s] += marks[c][s][sub];
            }
            printf("Class %d, Student %d: %d\n", c + 1, s + 1, total[c][s]);
        }
    }

    // topper of each class
    for (c = 0; c < 2; c++) {
        topStudent[c] = 0;
        for (s = 1; s < 3; s++) {
            if (total[c][s] > total[c][topStudent[c]]) {
                topStudent[c] = s;
            }
        }
    }

    // overall topper
    for (c = 0; c < 2; c++) {
        for (s = 0; s < 3; s++) {
            if (total[c][s] > total[overallClass][overallStudent]) {
                overallClass = c;
                overallStudent = s;
            }
        }
    }

    printf("\n");
    for (c = 0; c < 2; c++) {
        printf("Top Performer of Class %d: Student %d with %d marks\n",
               c + 1, topStudent[c] + 1, total[c][topStudent[c]]);
    }
    printf("Overall Topper: Class %d, Student %d with %d marks\n",
           overallClass + 1, overallStudent + 1, total[overallClass][overallStudent]);

    return 0;
}