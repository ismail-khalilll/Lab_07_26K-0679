#include <stdio.h>

int main() {
    int seats[10][4];
    int i, j, n, row, seat;
    int fullRows = 0;

    // all seats free at the start
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            seats[i][j] = 0;
        }
    }

    printf("How many seats do you want to reserve? ");
    scanf("%d", &n);

    if (n > 40) {
        printf("Only 40 seats exist, so reserving 40.\n");
        n = 40;
    }

    for (i = 0; i < n; i++) {
        // keep asking until we get a valid, free seat
        while (1) {
            printf("Booking %d - enter row (1-10) and seat (1-4): ", i + 1);
            scanf("%d %d", &row, &seat);

            if (row < 1 || row > 10 || seat < 1 || seat > 4) {
                printf("Invalid row or seat number, try again.\n");
                continue;
            }
            if (seats[row - 1][seat - 1] == 1) {
                printf("Seat already booked\n");
                continue;
            }
            seats[row - 1][seat - 1] = 1;
            break;
        }
    }

    printf("\nSeating arrangement (0 = free, 1 = reserved)\n");
    for (i = 0; i < 10; i++) {
        printf("Row %2d: ", i + 1);
        for (j = 0; j < 4; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }

    // a row is full only if every seat in it is 1
    for (i = 0; i < 10; i++) {
        int full = 1;
        for (j = 0; j < 4; j++) {
            if (seats[i][j] == 0) {
                full = 0;
            }
        }
        if (full) {
            fullRows++;
        }
    }

    printf("\nTotal fully booked rows: %d\n", fullRows);
    return 0;
}