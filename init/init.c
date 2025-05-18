#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init_unif(float *v, int size, float low, float high){
    float x;
    for (int i = 0; i < size; i++){
        x = (float)rand() / (float)RAND_MAX;
        v[i] = x * (high - low) + low;
    }
}

void print_as_matrix(float *vec, int row, int col, char * msg){
    printf("%s=\n[[", msg);
    for (int j = 0; j < row * col; j++)
    {
        if (j % col == 0 && j > 0) {
            printf("],\n [");
        } else if ( j > 0) {
            printf(", ");
        }
        printf("%.3f", vec[j]);
    }
    printf("]]\n");
}

int main(void)
{

    srand(time(NULL));

    // Initialize
    int B = 6;
    int C = 8;
    float* out = malloc(B * C * sizeof(float));

    // Calculate
    init_unif(out, B * C, -5., 5.);
    print_as_matrix(out, B, C, "Weights");
    printf("Complete.\n");

    // Clean up
    free(out);
    return 0;
}