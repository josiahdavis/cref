// -- Poor man's csv file loader --
// Assumes all data is numerical with no header. 
// Stores in row-wise format.
// Utility to print first n rows.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void head(float *d, int ncols, int n){
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < ncols; j++){
            if (j == 0) printf("| ");
            printf("%2.0f", d[i * ncols + j]);
            printf(" | ");
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int max_line_len = 10000;
    char line[max_line_len];
    int nrows = 10;
    int ncols = 5;
    char *token;

    float *data = malloc(nrows * ncols * sizeof(float));
    if (data == NULL) {
        perror("Memory allocation failed\n");
        return 1;
    }

    FILE *file = fopen("data.csv", "r");
    if (file == NULL){
        perror("Missing file\n");
        return 1;
    }

    for (int i = 0; i < nrows; i++){
        fgets(line, max_line_len, file);
        for (int j = 0; j < ncols; j++){
            token = strtok(j == 0 ? line : NULL, ",");
            if (token == NULL){
                perror("Error parsing row");
                fclose(file);
                return 1;
            }
            data[i * ncols + j] = atof(token);
        }
    }
    head(data, ncols, 5);
    fclose(file);
    free(data);
    printf("Loaded csv data\n");
    return 0;
}