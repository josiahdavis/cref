#include <stdio.h>
/*
shellsort: sort v[0]...v[n-1] into increasing order
Invented by D.L. Shell in 1959.
p. 63 from K&R
*/

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        printf("\ngap=%d", gap);
        for (i = gap; i < n; i++)
        {
            printf("\n\ti=%d", i);
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                printf("\n\t\tj=%d", j);
                printf("\n\t\tSwapping v[j]=%d and v[j + gap]=%d", v[j], v[j + gap]);
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void printarr(int v[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("{%d, ", v[i]);
        }
        else if (i == (n - 1))
        {
            printf("%d}", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 1, 5, 1, 2, 3, 1, 5, 1, 2};
    int n = 10;
    printarr(arr, n);
    shellsort(arr, n);
    printarr(arr, n);
}
