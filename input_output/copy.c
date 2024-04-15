#include <stdio.h>

int main()
{
    // Print out EOF
    printf("%d", EOF);

    // Verify that the getchar != EOF is either 0 or 1
    // printf("First try %d", getchar() != EOF);
    // printf("Second try %d", getchar() != EOF);
    // printf("Third try %d", getchar() != EOF);
    // printf("Fourth try %d", getchar() != EOF);

    int c;
    c = getchar();
    // putchar(c);
    // printf('EOF');
    int i;
    i = 0;
    while (c != EOF)
    {
        printf("result %d: %d\n", i, c != EOF);
        putchar(c);
        c = getchar();
        ++i;
    }
}