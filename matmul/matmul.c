#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_as_matrix(float *vec, int n, int col, char * msg){
    printf("%s=\n[[", msg);
    for (int j = 0; j < n; j++)
    {
        if (j % col == 0 && j > 0) {
            printf("],\n [");
        } else if ( j > 0) {
            printf(", ");
        }
        printf("%.0f", vec[j]);
    }
    printf("]]\n");
}

void matmul(float* x, float* Wx, float* out, int B, int C){
    // x is B x C
    // Wx is C x C
    // out is B x C

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
    float tol = 0.0001;
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
    int B = 2;
    int C = 3;
    float* x = malloc(B * C * sizeof(float));
    float* Wx = malloc(C * C * sizeof(float));
    float* out = malloc(B * C * sizeof(float));
    float* out_expected = malloc(B * C * sizeof(float));

    FILE *file = fopen("matmul.bin", "rb");
    if (file == NULL){
        perror("Error opening file\n");
    }
    
    // Read in the same order as write
    fread(x, sizeof(float), B * C, file);
    fread(Wx, sizeof(float), C * C, file);
    fread(out_expected, sizeof(float), B * C, file);

    // Print out
    print_as_matrix(x, B * C, C, "x");
    print_as_matrix(Wx, C * C, C, "Wx");
    print_as_matrix(out_expected, B * C, C, "expected");

    // Calculate
    matmul(x, Wx, out, B, C);
    print_as_matrix(out, B * C, C, "calculated");

    // Check
    int equal = all_close(out, out_expected, B * C);
    if (equal == 1) printf("✅ SUCCESS\n");
    else if (equal == 0) printf("❌ ERROR\n");
    
    // Clean up
    free(x);
    free(Wx);
    free(out);
    free(out_expected);
    return 0;
}