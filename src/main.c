#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main() {

    DIR *directoryPointer;
    struct dirent *entry;
    char input[256];

    printf("Input directory using format:\nC:/Example/Example2/\n> ");
    // scanf("%s", &path);
    // fgets has a \n at the end by default so it does not work
    fgets(input, 256, stdin);
    int len = (strlen(input)) - 1;
    char path[len];
    memcpy(path, input, len);
    // printf("%s\n", path);

    directoryPointer = opendir(path);
    if (directoryPointer == NULL)
    {
        perror("opendir");
    }

    printf("Contents of the \"%s\" directory:\n", path);
    while ((entry = readdir(directoryPointer)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    if (closedir(directoryPointer) != 0)
    {
        perror("closedir");
    }

    return 0;
}