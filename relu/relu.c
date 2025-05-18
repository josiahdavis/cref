#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(float *v, int size){
    for (int i = 0; i < size; i++){
        v[i] = (float)rand() / (float)RAND_MAX * 10. - 10./2.;
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

void relu(float *v, int size){
    for (int i = 0; i < size; i++){
        if (v[i] < 0) v[i] = 0;
    }
}

int main(void)
{
    // Initialize
    int B = 4;
    int C = 5;
    float* out = malloc(B * C * sizeof(float));

    // Calculate
    init(out, B * C);
    print_as_matrix(out, B, C, "before");
    relu(out, B * C);
    print_as_matrix(out, B, C, "after");
    printf("Complete.\n");

    // Clean up
    free(out);
    return 0;
}