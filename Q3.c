#include <stdio.h>

int main() {
    float sales[4][5];
    float salesmanTotal[4];
    float productTotal[5];
    int i, j;
    int best = 0;

    printf("Enter sales (in Rs.) for each salesman and product:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("Salesman %d, Product %d: ", i + 1, j + 1);
            scanf("%f", &sales[i][j]);
        }
    }

    // total for each salesman (row-wise)
    for (i = 0; i < 4; i++) {
        salesmanTotal[i] = 0;
        for (j = 0; j < 5; j++) {
            salesmanTotal[i] += sales[i][j];
        }
    }

    // total for each product (column-wise)
    for (j = 0; j < 5; j++) {
        productTotal[j] = 0;
        for (i = 0; i < 4; i++) {
            productTotal[j] += sales[i][j];
        }
    }

    // product with the highest revenue
    for (j = 1; j < 5; j++) {
        if (productTotal[j] > productTotal[best]) {
            best = j;
        }
    }

    printf("\n--- Total sales per salesman ---\n");
    for (i = 0; i < 4; i++) {
        printf("Salesman %d: Rs. %.2f\n", i + 1, salesmanTotal[i]);
    }

    printf("\n--- Total sales per product ---\n");
    for (j = 0; j < 5; j++) {
        printf("Product %d: Rs. %.2f\n", j + 1, productTotal[j]);
    }

    printf("\nMost expensive (highest revenue) product: Product %d with Rs. %.2f\n",
           best + 1, productTotal[best]);

    printf("\n--- Final amounts after bonus ---\n");
    for (i = 0; i < 4; i++) {
        float finalAmount = salesmanTotal[i];
        if (salesmanTotal[i] > 10000) {
            finalAmount = salesmanTotal[i] + salesmanTotal[i] * 0.10;
            printf("Salesman %d: Rs. %.2f (10%% bonus applied)\n", i + 1, finalAmount);
        } else {
            printf("Salesman %d: Rs. %.2f (no bonus)\n", i + 1, finalAmount);
        }
    }

    return 0;
}