#include <stdio.h>

// Define the number of months and the period for moving averages
#define MONTH_COUNT 12
#define MOVING_AVERAGE_PERIOD 6

// Function to find the minimum, maximum, and average sales
void calculateSalesSummary(const float sales[], float *minSales, float *maxSales, float *averageSales) {
    *minSales = *maxSales = *averageSales = sales[0];

    for (int i = 1; i < MONTH_COUNT; i++) {
        if (sales[i] < *minSales) {
            *minSales = sales[i];
        }
        if (sales[i] > *maxSales) {
            *maxSales = sales[i];
        }
        *averageSales += sales[i];
    }

    *averageSales /= MONTH_COUNT;
}

// Function to print a simple sales report
void printSalesReport(const char *months[], const float sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month     Sales\n");

    for (int month = 0; month < MONTH_COUNT; month++) {
        printf("%-9s $%.2f\n", months[month], sales[month]);
    }
}

// Function to print the sales summary
void printSalesSummary(float minSales, float maxSales, float averageSales, const char *firstMonth, const char *lastMonth) {
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, firstMonth);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, lastMonth);
    printf("Average sales: $%.2f\n", averageSales);
}

// Function to calculate and print the six-month moving averages
void printMovingAverages(const char *months[], const float sales[]) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int startMonth = 0; startMonth < MONTH_COUNT - MOVING_AVERAGE_PERIOD + 1; startMonth++) {
        float movingAverage = 0;

        for (int i = startMonth; i < startMonth + MOVING_AVERAGE_PERIOD; i++) {
            movingAverage += sales[i];
        }

        movingAverage /= MOVING_AVERAGE_PERIOD;
        printf("%s - %s $%.2f\n", months[startMonth], months[startMonth + MOVING_AVERAGE_PERIOD - 1], movingAverage);
    }
}

// Function to sort sales and months in descending order and print the report
void printSortedSalesReport(const char *months[], float sales[]) {
    printf("\nSales Report (Highest to Lowest)\n");
    printf("Month      Sales\n");

    for (int i = 0; i < MONTH_COUNT - 1; i++) {
        for (int j = 0; j < MONTH_COUNT - 1 - i; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap sales
                float tempSales = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSales;

                // Swap months
                const char *tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }

    for (int month = 0; month < MONTH_COUNT; month++) {
        printf("%-9s $%.2f\n", months[month], sales[month]);
    }
}

int main() {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

    float minSales, maxSales, averageSales;

    calculateSalesSummary(sales, &minSales, &maxSales, &averageSales);
    printSalesReport(months, sales);
    printSalesSummary(minSales, maxSales, averageSales, months[0], months[MONTH_COUNT - 1]);
    printMovingAverages(months, sales);
    printSortedSalesReport(months, sales);

    return 0;
}
