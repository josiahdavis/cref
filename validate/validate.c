// Compute summary stats on a vector

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float mean_calc(float *vec, int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
    }
    return sum / (float)n;
}

float std_calc(float *vec, float mean, int n)
{
    float sum_squared_diff = 0.0f;
    for (int i = 0; i < n; i++)
    {
        float diff = vec[i] - mean;
        sum_squared_diff +=  (diff * diff);
    }
    return sqrtf(sum_squared_diff / (float)n);
}

void all_close(float *v1, float *v2, int size){
    float tol = 0.001;
    for (int i = 0; i < size; i++){
        if( fabs(v1[i] - v2[i]) > tol) {
            printf("❌ ERROR\n");
            return;
        }
    }
    printf("✅ SUCCESS\n");
}

void normalize(float *x, float *out, float mean, float std, int size){
    for (int i = 0; i < size; i++){
        out[i] = (x[i] - mean) / std;
    }
}

int main(){

    // initialize vector
    int size = 10000;
    float mean, std;
    float* x = malloc(size * sizeof(float));
    float* out = malloc(size * sizeof(float));
    float* out_expected = malloc(size * sizeof(float));

    FILE *file = fopen("basicstats.bin", "rb");
    if (file == NULL) {
        perror("Error opening file\n");
    }

    // Read in the same order as write
    fread(x, sizeof(float), size, file);
    fread(out_expected, sizeof(float), size, file);

    // Calculate basic statistics
    mean = mean_calc(x, size);
    std = std_calc(x, mean, size);
    printf("mean=%.4f, std=%.4f\n", mean, std);
    normalize(x, out, mean, std, size);

    // Check
    all_close(out, out_expected, size);

    // Cleanup 
    free(x);
    free(out);
    free(out_expected);
    return 0;
}