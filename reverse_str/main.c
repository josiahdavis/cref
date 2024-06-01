#include <stdio.h>
#include <string.h>

// Reverse string s in place

void reverse(char s[])
{
    int c, i, j;
    printf("\nCharacter array is %lu long", strlen(s));
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        printf("\n-- i=%d, j=%d --", i, j);
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    // A "string" in C is a character array
    char msg[] = "Luka Magic";
    char msg2[] = "NBA Finals";

    printf("\nOriginal character array: %s", msg);
    reverse(msg);
    printf("\nModified character array: %s \n", msg);

    printf("\nOriginal character array: %s", msg2);
    reverse(msg2);
    reverse(msg2);
    printf("\nOriginal character array: %s \n", msg2);
}