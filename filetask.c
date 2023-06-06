#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

int main()
{
    char line[MAX_LINE_LENGTH];
    int count = 0;
    FILE *file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Can't open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        count++;
        int length = strlen(line);

        // if (length > 0 && line[length-1] == '\n') {
        //     line[length-1] = '\0';
        //     length--;
        // }

        printf("%d %.*s", length, 10, line);

        if (length < 10) {
            for (int i=0; i<10-length; i++) {
                printf("%c", line[length-1]);
            }
        }

        printf("\n");
    }

    fclose(file);
    return 0;
}





