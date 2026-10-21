#include <stdio.h>

int main() {
    int i, j;

    // normal triangle
    printf("Pattern 1:\n");
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // reversed triangle
    printf("\nPattern 2 (reversed):\n");
    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // multiplication version, i x j
    printf("\nPattern 3 (multiplication):\n");
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }

    return 0;
}