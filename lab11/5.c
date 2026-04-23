#include <stdio.h>
#include <string.h>
struct Department {
 char deptCode[10];
 char deptName[50];
};
struct Course {
 char courseCode[10];
 char courseName[60];
 int creditHours;
 struct Department dept;
};
void filterByDept(struct Course c[], int n, char *code) {
 int i, found = 0;
 for (i = 0; i < n; i++) {
 if (strcmp(c[i].dept.deptCode, code) == 0) {
 printf(" %s - %s (%d credits)\n", c[i].courseCode, c[i].courseName,
c[i].creditHours);
 found = 1;
 }
 }
 if (found == 0)
 printf(" No courses found for this department.\n");
}
int main() {
 struct Course c[3];
 char searchCode[10];
 int i;
 for (i = 0; i < 3; i++) {
 printf("Course %d:\n", i + 1);
 printf(" Course Code: ");
 scanf("%s", c[i].courseCode);
 getchar();
 printf(" Course Name: ");
 fgets(c[i].courseName, 60, stdin);
 c[i].courseName[strlen(c[i].courseName) - 1] = '\0';
 printf(" Credit Hours: ");
 scanf("%d", &c[i].creditHours);
 printf(" Department Code: ");
 scanf("%s", c[i].dept.deptCode);
 getchar();
 printf(" Department Name: ");
 fgets(c[i].dept.deptName, 50, stdin);
 c[i].dept.deptName[strlen(c[i].dept.deptName) - 1] = '\0';
 printf("\n");
 }
 printf("--- All Courses ---\n");
 for (i = 0; i < 3; i++) {
 printf("Course: %s - %s\n", c[i].courseCode, c[i].courseName);
 printf("Credits: %d\n", c[i].creditHours);
 printf("Dept: %s (%s)\n", c[i].dept.deptName, c[i].dept.deptCode);
 printf("\n");
 }
 printf("Enter department code to filter: ");
 scanf("%s", searchCode);
 printf("\nCourses in %s:\n", searchCode);
 filterByDept(c, 3, searchCode);
 return 0;
}

