#include <stdio.h>

int main() {
    int data[3][3], key[3][3], enc[3][3];
    int i, j;
    int max, maxRow = 0, maxCol = 0;

    printf("Enter the data matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Data[%d][%d]: ", i, j);
            scanf("%d", &data[i][j]);
        }
    }

    printf("\nEnter the key matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Key[%d][%d]: ", i, j);
            scanf("%d", &key[i][j]);
        }
    }

    // Encrypted = (Data * Key) + (i + j)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            enc[i][j] = (data[i][j] * key[i][j]) + (i + j);
        }
    }

    printf("\nEncrypted matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%6d", enc[i][j]);
        }
        printf("\n");
    }

    max = enc[0][0];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (enc[i][j] > max) {
                max = enc[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    printf("\nMaximum encrypted value: %d at (row %d, column %d)\n", max, maxRow, maxCol);
    return 0;
}