#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *sensorData;

    printf("Enter number of sensors: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of sensors.\n");
        return 0;
    }

    sensorData = (float *)calloc(n, sizeof(float));

    if (sensorData == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("\nInitial values after calloc:\n");
    for (i = 0; i < n; i++) {
        printf("Sensor %d: %.1f\n", i + 1, sensorData[i]);
    }

    printf("\nEnter temperature readings:\n");
    for (i = 0; i < n; i++) {
        printf("Sensor %d reading: ", i + 1);
        scanf("%f", &sensorData[i]);
    }

    printf("\n--- Final Sensor Readings ---\n");
    for (i = 0; i < n; i++) {
        printf("Sensor %d: %.2f\n", i + 1, sensorData[i]);
    }

    printf("\nComparison:\n");
    printf("calloc initializes all values to 0.0.\n");
    printf("malloc leaves indeterminate garbage values until they are assigned.\n");

    free(sensorData);
    sensorData = NULL;

    return 0;
}
