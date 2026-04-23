#include <stdio.h>
#include <string.h>
int countWays(int n) {
 if (n == 0 || n == 1)
 return 1;
 return countWays(n - 1) + countWays(n - 2);
}
void printPaths(int n, int moves[], int idx) {
 int i;
 if (n == 0) {
 for (i = 0; i < idx; i++) {
 if (i > 0) printf("+");
 printf("%d", moves[i]);
 }
 printf("\n");
 return;
 }
 if (n >= 1) {
 moves[idx] = 1;
 printPaths(n - 1, moves, idx + 1);
 }
 if (n >= 2) {
 moves[idx] = 2;
 printPaths(n - 2, moves, idx + 1);
 }
}
int main() {
 int n;
 int moves[20];
 printf("Enter N (1-15): ");
 scanf("%d", &n);
 printf("Number of ways: %d\n", countWays(n));
 printf("\nPaths for N = %d:\n", n);
 printPaths(n, moves, 0);
 return 0;
}

