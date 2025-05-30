#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init_unif(float *v, int size, float low, float high){
    float x;
    for (int i = 0; i < size; i++){
        x = (float)rand() / (float)RAND_MAX;
        v[i] = x * (high - low) + low;
        // v[i] = (float)(rand() % 10);
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

void softmax(float *v, float *v_out, int rows, int cols){
    float *row_sums = malloc(rows * sizeof(float));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            row_sums[i] += v[i * cols + j];
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            v_out[i * cols + j] = v[i * cols + j] / row_sums[i];
        }
    }
}

int main(void)
{

    srand(time(NULL));

    // Initialize
    int B = 6;
    int C = 2;
    float* W_in = malloc(B * C * sizeof(float));
    float* W_out = malloc(B * C * sizeof(float));

    // Calculate
    init_unif(W_in, B * C, -5., 5.);
    print_as_matrix(W_in, B, C, "Weights in");
    softmax(W_in, W_out, B, C);
    print_as_matrix(W_out, B, C, "Softmax");
    printf("Complete.\n");

    // Clean up
    free(W_in);
    free(W_out);
    return 0;
}