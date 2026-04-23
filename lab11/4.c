#include <stdio.h>
#include <string.h>
struct Patient {
 char name[50];
 int age;
 char bloodType[5];
 int patientID;
 char diagnosis[100];
};
void displayAll(struct Patient p[], int n) {
 int i;
 printf("\n%-5s %-20s %-5s %-6s %s\n", "ID", "Name", "Age", "Blood", "Diagnosis");
 printf("-----------------------------------------------------------\n");
 for (i = 0; i < n; i++) {
 printf("%-5d %-20s %-5d %-6s %s\n", p[i].patientID, p[i].name, p[i].age,
p[i].bloodType, p[i].diagnosis);
 }
}
void searchByID(struct Patient p[], int n, int id) {
 int i;
 for (i = 0; i < n; i++) {
 if (p[i].patientID == id) {
 printf("\nPatient Found:\n");
 printf("ID: %d\n", p[i].patientID);
 printf("Name: %s\n", p[i].name);
 printf("Age: %d\n", p[i].age);
 printf("Blood Type: %s\n", p[i].bloodType);
 printf("Diagnosis: %s\n", p[i].diagnosis);
 return;
 }
 }
 printf("Patient not found\n");
}
int main() {
 struct Patient p[5];
 int i, searchID;
 for (i = 0; i < 5; i++) {
 printf("Patient %d:\n", i + 1);
 printf(" ID: ");
 scanf("%d", &p[i].patientID);
 getchar();
 printf(" Name: ");
 fgets(p[i].name, 50, stdin);
 p[i].name[strlen(p[i].name) - 1] = '\0';
 printf(" Age: ");
 scanf("%d", &p[i].age);
 getchar();
 printf(" Blood Type: ");
 scanf("%s", p[i].bloodType);
 getchar();
 printf(" Diagnosis: ");
 fgets(p[i].diagnosis, 100, stdin);
 p[i].diagnosis[strlen(p[i].diagnosis) - 1] = '\0';
 printf("\n");
 }
 displayAll(p, 5);
 printf("\nEnter Patient ID to search: ");
 scanf("%d", &searchID);
 searchByID(p, 5, searchID);
 return 0;
}

