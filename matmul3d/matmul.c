#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_as_matrix(float *vec, int row, int col){
    printf("[[");
    for (int j = 0; j < row * col; j++)
    {
        if (j % col == 0 && j > 0) {
            printf("],\n [");
        } else if ( j > 0) {
            printf(", ");
        }
        printf("%2.0f", vec[j]);
    }
    printf("]]");
}

void print_as_matrix_3d(float *vec, int batch, int row, int col){
    printf("\n[");
    for (int b = 0; b < batch; b++){
        if (b > 0) printf("\n\n");
        print_as_matrix(&vec[b * (row * col)], row, col);
    }
    printf("]\n\n");
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

void matmul(float* x, float* Wx, float* out, int B, int T, int C_in, int C_out){
    // out = x @ Wx
    //
    // x is B x T x C_in
    // Wx is C_in x C_out
    // out is B x T x C_out

    for (int b = 0; b < B; b++){
        for (int t = 0; t < T; t++){
            for (int c = 0; c < C_out; c++){
                // compute dot product of row of x and column of Wx.
                float dot = 0.0f;
                for (int i = 0; i < C_in; i++){
                    // formula for indexing into a 3D matrix to get correct element:
                    //      mat_index * row_dim * col_dim + row_index * col_dim + col_index
                    //      batch_idx * seq_len * n_embd + seq_idx * n_embd + embd_idx
                    dot += x[b * T * C_in + t * C_in + i] * Wx[i * C_out + c];
                }
                out[b * T * C_out + t * C_out + c] = dot;
            }
        }
    }
}

int main(void)
{
    // Initialize
    int B = 2;
    int T = 3;
    int C_in = 4;
    int C_out = 5;
    float* x = malloc(B * T *  C_in * sizeof(float));
    float* Wx = malloc(C_in * C_out * sizeof(float));
    float* out = malloc(B * T * C_out * sizeof(float));
    float* out_expected = malloc(B * T * C_out * sizeof(float));

    FILE *file = fopen("matmul.bin", "rb");
    if (file == NULL){
        perror("Error opening file\n");
    }

    // Read in the same order as write
    fread(x, sizeof(float), B * T * C_in, file);
    fread(Wx, sizeof(float), C_in * C_out, file);
    fread(out_expected, sizeof(float), B * T * C_out, file);

    // Print out
    printf("x"); print_as_matrix_3d(x, B, T, C_in);
    printf("Wx\n"); print_as_matrix(Wx, C_in, C_out);
    printf("\n\nExpected"); print_as_matrix_3d(out_expected, B, T, C_out);

    // Calculate
    matmul(x, Wx, out, B, T, C_in, C_out);
    printf("Calculated"); print_as_matrix_3d(out, B, T, C_out);

    // Check
    int equal = all_close(out, out_expected, B * C_out);
    if (equal == 1) printf("✅ SUCCESS\n");
    else if (equal == 0) printf("❌ ERROR\n");
    
    // Clean up
    free(x);
    free(Wx);
    free(out);
    free(out_expected);
    return 0;
}