#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>

void matmul(float* x, float* Wx, float* out, int B, int C){
    // x is B x C
    // Wx is C x C
    // out is B x C

    #pragma omp parallel for collapse(2)
    for (int b = 0; b < B; b++){
        for (int c = 0; c < C; c++){
            // compute dot product of row of x and column of Wx.
            float dot = 0.0f;
            for (int i = 0; i < C; i++){
                // formula for indexing into a matrix to get correct element:
                //      row index * column width + column index
                dot += x[b * C + i] * Wx[i * C + c];
            }
            out[b * C + c] = dot;
        }
    }
}

int all_close(float *v1, float *v2, int size){
    float tol = 0.01;
    for (int i = 0; i < size; i++){
        if( fabs(v1[i] - v2[i]) > tol) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    // Initialize
    int B = 64;
    int C = 512;
    float* x = malloc(B * C * sizeof(float));
    float* Wx = malloc(C * C * sizeof(float));
    float* out = malloc(B * C * sizeof(float));
    float* out_expected = malloc(B * C * sizeof(float));

    // Read data
    FILE *file = fopen("matmul.bin", "rb");
    if (file == NULL){
        perror("Error opening file\n");
    }
    
    // (same order as write)
    fread(x, sizeof(float), B * C, file);
    fread(Wx, sizeof(float), C * C, file);
    fread(out_expected, sizeof(float), B * C, file);

    // Calculate
    double start_time = omp_get_wtime();
    matmul(x, Wx, out, B, C);
    double run_time = (omp_get_wtime() - start_time);

    // Check
    char * msg;
    int equal = all_close(out, out_expected, B * C);
    msg = equal == 1 ? "✅ SUCCESS" : "❌ ERROR";
    printf("%s in %f secs \n", msg, run_time);

    // Clean up
    free(x);
    free(Wx);
    free(out);
    free(out_expected);
    fclose(file);
    return 0;
}