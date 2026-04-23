#include <stdio.h>
#include <ctype.h>
int countUpper(char *str) {
 if (str[0] == '\0')
 return 0;
 if (isupper(str[0]))
 return 1 + countUpper(str + 1);
 return countUpper(str + 1);
}
int countDigits(char *str) {
 if (str[0] == '\0')
 return 0;
 if (isdigit(str[0]))
 return 1 + countDigits(str + 1);
 return countDigits(str + 1);
}
int main() {
 char pass[50];
 printf("Enter password: ");
 scanf("%s", pass);
 printf("Uppercase letters: %d\n", countUpper(pass));
 printf("Digits: %d\n", countDigits(pass));
 return 0;
}

