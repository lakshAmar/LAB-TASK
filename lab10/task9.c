#include <stdio.h>

int main() {

    FILE *fptr;
    char line[100];

    fptr = fopen("config.txt", "r");

    if (fptr == NULL) {
        printf("Config file not found. Creating default config.txt...\n");

        fptr = fopen("config.txt", "w");
        if (fptr == NULL) {
            printf("Error: Cannot create file.\n");
            return 0;
        }

        fprintf(fptr, "max_users=50\n");
        fprintf(fptr, "timeout=30\n");
        fprintf(fptr, "debug=off\n");
        fclose(fptr);

        printf("Default config created with 3 settings.\n");
    }
    else {

        printf("Config file found. Reading settings...\n\n");
        while (fgets(line, 100, fptr) != NULL) {
            printf("%s", line);
        }
        fclose(fptr);
    }

    return 0;
}


