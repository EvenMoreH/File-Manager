#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>      // allows for tolower() funtion

DIR *directoryPointer;
struct dirent *entry;
char input[256];
char leave;

int main() {

    do
    {
        printf("Input directory using format:\nC:/Example/Example2\n> ");
        scanf("%255[^\n]", input);

        directoryPointer = opendir(input);
        if (directoryPointer == NULL)
        {
            perror("opendir");
        }

        printf("Contents of the \"%s\" directory:\n", input);
        while ((entry = readdir(directoryPointer)) != NULL)
        {
            printf("%s\n", entry->d_name);
        }

        if (closedir(directoryPointer) != 0)
        {
            perror("closedir");
        }
        printf("\n------------------------------------------");
        printf("\n\nPress Y to exit.\n> ");
        scanf(" %1c", &leave);
        leave = tolower(leave);
    } while (leave != 'y');

    return 0;
}