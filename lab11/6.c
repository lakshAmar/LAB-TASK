#include <stdio.h>
#include <string.h>
struct Order {
 int orderID;
 char customer[50];
 char product[50];
 int quantity;
 float unitPrice;
 char status[15];
};
float computeTotal(struct Order o) {
 return o.quantity * o.unitPrice;
}
void filterByStatus(struct Order orders[], int n, char *status) {
 int i, found = 0;
 for (i = 0; i < n; i++) {
 if (strcmp(orders[i].status, status) == 0) {
 printf(" Order %d: %s - %s (Qty: %d, Total: %.2f)\n",
 orders[i].orderID, orders[i].customer,
 orders[i].product, orders[i].quantity,
 computeTotal(orders[i]));
 found = 1;
 }
 }
 if (found == 0)
 printf(" No orders with status '%s'\n", status);
}
int main() {
 struct Order o[4];
 char search[15];
 int i;
 for (i = 0; i < 4; i++) {
 printf("Order %d:\n", i + 1);
 printf(" Order ID: ");
 scanf("%d", &o[i].orderID);
 getchar();
 printf(" Customer: ");
 fgets(o[i].customer, 50, stdin);
 o[i].customer[strlen(o[i].customer) - 1] = '\0';
 printf(" Product: ");
 fgets(o[i].product, 50, stdin);
 o[i].product[strlen(o[i].product) - 1] = '\0';
 printf(" Quantity: ");
 scanf("%d", &o[i].quantity);
 printf(" Unit Price: ");
 scanf("%f", &o[i].unitPrice);
 getchar();
 printf(" Status (Pending/Shipped/Delivered): ");
 scanf("%s", o[i].status);
 printf("\n");
 }
 printf("--- Itemized Bills ---\n");
 for (i = 0; i < 4; i++) {
 printf("Order %d: %s - %s | Qty: %d x %.2f = Rs. %.2f\n",
 o[i].orderID, o[i].customer, o[i].product,
 o[i].quantity, o[i].unitPrice, computeTotal(o[i]));
 }
 printf("\nEnter status to filter: ");
 scanf("%s", search);
 printf("\nOrders with status '%s':\n", search);
 filterByStatus(o, 4, search);
 return 0;
}

