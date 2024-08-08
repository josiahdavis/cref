#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// Modified from Umang Kaushik's: 
// https://github.com/ubermenchh/Flash/blob/main/flash.c


// The size_t data type in C is an unsigned integer 
// type used to represent the size of objects in bytes.

typedef struct {
    size_t size;
    double* data;
} Vector;

Vector* InitVector(size_t size) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    vector->size = size;
    vector->data = (double*)calloc(size, sizeof(double));
    return vector;
}

void PrintVector(Vector* v) {
    printf("Vector(data=([");
    for (int i = 0; i < v->size; i++) {
        printf(" %f", v->data[i]);
    }
    printf(" ]), size=%zu)\n\n", v->size);
}

Vector* RandomVector(size_t size, int seed) {
    if (seed != 0) {
        srand(seed);
    } else {
        srand(time(NULL));
    }
    Vector* out = InitVector(size);
    for (int i = 0; i < size; i++) {
        out->data[i] = (double)rand() / (double)RAND_MAX;
    }
    return out;
}

Vector* VectorAdd(Vector* v, Vector* w) {
    assert(v->size == w->size);
    Vector* out = InitVector(v->size);

    for (int i = 0; i < out->size; i++) {
        out->data[i] = (v->data[i] + w->data[i]);
    }
    return out;
}

double VectorDotProduct(Vector* v, Vector* w){
    assert(v->size == w->size);
    double out = 0.0;

    for (int i = 0; i < v->size; i++){
        out += v->data[i] * w->data[i];
    }
    return out;
}

Vector* VectorScale(Vector* v, double scalar){
    Vector* out = InitVector(v->size);
    for (int i = 0; i < v->size;i++) {
        out->data[i] = v->data[i] * scalar;
    }
    return out;
}

Vector* VectorMultiply(Vector* v, Vector* w){
    assert(v->size == w->size);
    Vector* out = InitVector(v->size);
    for (int i =  0; i < v->size; i++){
        out->data[i] = v->data[i] * w->data[i];
    }
    return out;
}

int main()
{
    /* ---------------
    -- Vectors --
    ---------------*/

    printf("\nVECTORS\n-------------\n");

    Vector* v1 = RandomVector(2, 7041);
    Vector* v2 = RandomVector(2, 0);
    printf("Vector 1:\n");
    PrintVector(v1);
    printf("Vector 2:\n");
    PrintVector(v2);

    printf("Add\n-------------\n");
    Vector* v12 = VectorAdd(v1, v2);
    PrintVector(v12);

    printf("Dot Product\n-------------\n");
    double dot = VectorDotProduct(v1, v2);
    printf("dot = %f\n", dot);

    printf("\nScalar multiply\n-------------\n");
    Vector* v1_scaled = VectorScale(v1, 2.0);
    printf("v1 scaled by 2:\n");
    PrintVector(v1_scaled);

    printf("Element-wise multiply\n-------------\n");
    Vector* mult = VectorMultiply(v1, v2);
    printf("mult = ");
    PrintVector(mult);

}