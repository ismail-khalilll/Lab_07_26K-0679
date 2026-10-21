#include <stdio.h>

int main() {
    int i, j, s;

    // ---------- first set: simple triangles, 5 rows ----------
    for (i = 1; i <= 5; i++) {
        // stars (right aligned)
        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 0; j < i; j++) printf("* ");
        printf("  |   ");

        // numbers
        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 1; j <= i; j++) printf("%d ", j);
        printf("  |   ");

        // letters
        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 0; j < i; j++) printf("%c ", 'A' + j);
        printf("\n");
    }

    printf("\n");

    // ---------- second set: pyramids, 1,3,5,7,9 items per row ----------
    for (i = 1; i <= 5; i++) {
        int count = 2 * i - 1;

        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 0; j < count; j++) printf("* ");
        printf("  |   ");

        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 1; j <= count; j++) printf("%d ", j);
        printf("  |   ");

        for (s = 0; s < 5 - i; s++) printf("  ");
        for (j = 0; j < count; j++) printf("%c ", 'A' + j);
        printf("\n");
    }

    return 0;
}