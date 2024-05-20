#include <stdio.h>
#include <math.h>

void softmax(float *x, int size)
{

    // Numerator
    float sum = 0.0f;
    for (int i = 0; i < size; i++)
    {
        x[i] = expf(x[i]);
        sum += x[i];
    }

    // Denominator
    for (int i = 0; i < size; i++)
    {
        x[i] = x[i] / sum;
    }
}

int main()
{
    int size = 5;
    float x[5] = {1.0, 2.1, 3.2, 4.0, 5.0};

    softmax(x, size);
    for (int i = 0; i < size; i++)
    {
        printf("%f ", x[i]);
    }
}