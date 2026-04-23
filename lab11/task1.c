#include <stdio.h>
int floorPower(int f) {
 if (f == 1)
 return 100;
 return 2 * floorPower(f - 1);
}
int totalPower(int floors) {
 if (floors == 1)
 return 100;
 return floorPower(floors) + totalPower(floors - 1);
}
int main() {
 int n;
 printf("Enter number of floors: ");
 scanf("%d", &n);
 printf("Total power consumption: %d kWh\n", totalPower(n));
 return 0;
}


