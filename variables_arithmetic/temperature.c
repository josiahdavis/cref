#include <stdio.h>

// print Fahrenheit-Celsius table

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("%3s \t %6s\n", "C", "F");
    printf("----------------\n");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f \t %6.1f \n", fahr, celsius);
        fahr = fahr + step;
    }
}