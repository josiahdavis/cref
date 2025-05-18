#include <stdio.h>

int main(int argc, char *argv[])
{
    // 1. initialize variables
    int line_count=0;
    char c;
    char *file_name = argv[1];

    // 2. open file
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: file_name=%s not found\n", file_name);
        printf("Usage: ./lc <file_name>\n");
        return 1;
    }

    // 3. count new lines
    while (EOF != (c = fgetc(file))) {
        if (c == '\n') line_count++;
    }
    printf("%8d %s\n", line_count, file_name);
}