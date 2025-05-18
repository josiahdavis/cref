// Compute summary stats on a vector

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_vector(float *vec, int n){
    printf("[");
    int max_n = 25; // max elements to print
    for (int j = 0; j < n; j++)
    {
        if (j > max_n - 1) 
        {
            printf(", ...");
            break;
        }
        if (j > 0) printf(", ");
        printf("%.4f", vec[j]);
    }
    printf("]\n");
}

float randfloat(float upper) 
{
    return upper * ((float)rand() / (float)RAND_MAX);
}

float mean(float *vec, int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
    }
    return sum / (float)n;
}

float var(float *vec, float mean, int n)
{
    float sum_squared_diff = 0.0f;
    for (int i = 0; i < n; i++)
    {
        float diff = vec[i] - mean;
        sum_squared_diff +=  (diff * diff);
    }
    return sum_squared_diff / (float)n;
}

int main(){

    // initialize vector
    int n_elements = 15;
    float* v = malloc(n_elements * sizeof(float));

    srand(time(NULL));
    for (int i = 0; i<n_elements; i++)
    {
        v[i] = randfloat(100);
    }
    print_vector(v, n_elements);

    // calculate basic statistics
    float v_mean = mean(v, n_elements);
    float v_var = var(v, v_mean, n_elements);
    printf("Mean=%.4f\n", v_mean);
    printf("Variance=%.4f\n", v_var);
    printf("Standard Deviation=%.4f\n", sqrtf(v_var));

    free(v);
    return 0;
}