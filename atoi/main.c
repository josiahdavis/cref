// Naive implementation to convert a string "character array" to integer
#include <stdio.h>

int atoi(char s[])
{
    int n = 0, diff;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        diff = (s[i] - '0');
        // printf("diff=%d ", diff);
        printf("10 * %4d + %1d = ", n, diff);
        n = 10 * n + (s[i] - '0');
        printf("%d\n", n);
    }
    return n;
}

int main()
{
    char a[] = "2817";
    int n1;
    printf("Input #1: %s \n", a);
    n1 = atoi(a);
    printf("Output #1: %d \n", n1);

    char b[] = "51321";
    int n2;
    printf("\nInput #2: %s \n", b);
    n2 = atoi(a);
    printf("Output #2: %d \n", n2);
}