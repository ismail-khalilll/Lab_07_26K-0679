#include <stdio.h>

int main() {
    float temp[3][3][3];
    float layerAvg[3];
    int x, y, z;
    int hottest = 0;
    float maxTemp;
    int mx = 0, my = 0, mz = 0;

    printf("Enter the temperatures (in Celsius):\n");
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            for (z = 0; z < 3; z++) {
                printf("Point (%d, %d, %d): ", x, y, z);
                scanf("%f", &temp[x][y][z]);
            }
        }
    }

    // average of each layer (a layer is fixed z)
    for (z = 0; z < 3; z++) {
        float sum = 0;
        for (x = 0; x < 3; x++) {
            for (y = 0; y < 3; y++) {
                sum += temp[x][y][z];
            }
        }
        layerAvg[z] = sum / 9;
    }

    for (z = 1; z < 3; z++) {
        if (layerAvg[z] > layerAvg[hottest]) {
            hottest = z;
        }
    }

    // find the max point
    maxTemp = temp[0][0][0];
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            for (z = 0; z < 3; z++) {
                if (temp[x][y][z] > maxTemp) {
                    maxTemp = temp[x][y][z];
                    mx = x;
                    my = y;
                    mz = z;
                }
            }
        }
    }

    printf("\n--- Results ---\n");
    for (z = 0; z < 3; z++) {
        printf("Layer %d average: %.2f C\n", z + 1, layerAvg[z]);
    }
    printf("Hottest layer: Layer %d (average %.2f C)\n", hottest + 1, layerAvg[hottest]);
    printf("Maximum temperature: %.2f C at (%d, %d, %d)\n", maxTemp, mx, my, mz);

    return 0;
}