#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_as_matrix(float *vec, int row, int col, char * msg){
    printf("%s=\n[[", msg);
    for (int j = 0; j < row * col; j++)
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

// void print_as_matrix2(float *vec, int row, int col, char * msg){
//     printf("%s=\n[", msg);
//     for (int i = 0; i < row; i++){
//         // begin a new row
//         printf("\n[");

//     }
// }

int all_close(float *v1, float *v2, int size){
    float tol = 0.01;                                                          
    for (int i = 0; i < size; i++){
        if( fabs(v1[i] - v2[i]) > tol) {
            return 0;
        }
    }
    return 1;
}

void matmul(float* x, float* Wx, float* out, int B, int C_in, int C_out){
    // out = x @ Wx
    // x is B x C_in
    // Wx is C_in x C_out
    // out is B x C_out

    for (int b = 0; b < B; b++){
        for (int c = 0; c < C_out; c++){
            // compute dot product of row of x and column of Wx.
            float dot = 0.0f;
            for (int i = 0; i < C_in; i++){
                // formula for indexing into a matrix to get correct element:
                //      row index * column width + column index
                dot += x[b * C_in + i] * Wx[i * C_out + c];
            }
            out[b * C_out + c] = dot;
        }
    }
}

int main(void)
{
    // Initialize
    int B = 16;
    int C_in = 128;
    int C_out = 128;
    float* x = malloc(B * C_in * sizeof(float));
    float* Wx = malloc(C_in * C_out * sizeof(float));
    float* out = malloc(B * C_out * sizeof(float));
    float* out_expected = malloc(B * C_out * sizeof(float));

    FILE *file = fopen("matmul.bin", "rb");
    if (file == NULL){
        perror("Error opening file\n");
    }
    
    // Read in the same order as write
    fread(x, sizeof(float), B * C_in, file);
    fread(Wx, sizeof(float), C_in * C_out, file);
    fread(out_expected, sizeof(float), B * C_out, file);

    // Print out
    // print_as_matrix(x, B, C_in, "x");
    // print_as_matrix(Wx, C_in, C_out, "Wx");
    // print_as_matrix(out_expected, B, C_out, "expected");

    // Calculate
    matmul(x, Wx, out, B, C_in, C_out);
    // print_as_matrix(out, B, C_out, "calculated");

    // Check
    int equal = all_close(out, out_expected, B * C_out);
    if (equal == 1) printf("✅ SUCCESS\n");
    else if (equal == 0) printf("❌ ERROR\n");
    
    // Clean up
    free(x);
    free(Wx);
    free(out);
    free(out_expected);
    fclose(file);
    return 0;
}