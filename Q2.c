#include <stdio.h>

int main() {
    int grid[3][3];
    int i, j, k, l;
    int valid = 1;

    printf("Enter the 3x3 grid (0 for an empty cell):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Cell [%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }

    // range check
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                valid = 0;
            }
        }
    }

    // duplicate check - compare every cell with every other cell
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == 0) continue;   // ignore empty cells

            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    if ((k != i || l != j) && grid[i][j] == grid[k][l]) {
                        valid = 0;
                    }
                }
            }
        }
    }

    if (valid) {
        printf("Valid Grid\n");
    } else {
        printf("Invalid Grid\n");
    }
    return 0;
}