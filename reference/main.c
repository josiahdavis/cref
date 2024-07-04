#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_wrong(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_correct(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}


int main()
{

    /* --------------
    -- Data types --
    ---------------- */
    printf("\nData types\n-------------\n");

    // Integer
    int my_int = 143;
    printf("Integer:         %8d (use %%d to print)\n", my_int);

    // Floating Point
    float my_float = 143.142;
    printf("Floating Point:  %3.4f (use %%f to print)\n", my_float);

    // Floating Point (Scientific notation)
    float my_float2 = 3.8e-2;
    printf("Floating Point:  %3.2e (use %%e to print)\n", my_float2);

    // Double Precision
    double my_double = 143.142;
    printf("Double:          %3.4f (use %%f to print, also)\n", my_double);

    // Double Precision (Scientific notation)
    double my_double2 = 3.8e-2;
    printf("Double:          %3.2e (use %%e to print, also)\n", my_double2);

    // Character
    char my_char = 'a'; // Must use single quotes.
    printf("Character:       %8c (use %%c to print)\n", my_char);

    // String
    char my_char_arr[] = "learning";
    printf("Strings are character arrays\n");
    printf("Character Array: %8s (use %%s to print)\n", my_char_arr);

    // Boolean
    printf("Boolean data type does not exist\n");

    /* --------------
    -- Control Flow --
    ---------------- */
    printf("\nControl Flow\n-------------\n");

    int a = 10;
    int b = 10;
    // If else
    if (a == b)
    {
        printf("a == b");
    }
    else if (a > b)
    {
        printf("a > b");
    }
    else
    {
        printf("a < b");
    }

    // Shorthand If else 'ternary operator'
    (a >= b) ? printf("a >= b") : printf("a < b");

    // For loop
    int max_iter = 4;
    for (int i = 0; i < max_iter; i++)
    {
        printf("\niter = %d / %d", i, max_iter);
    }

    // While loop
    int j = 0;
    while (j < max_iter)
    {
        printf("\niter = %d / %d", j, max_iter);
        j++;
    }

    // Switch statement
    char abcs[] = "abcbbcccc";
    char letter;
    int a_count = 0, b_count = 0, c_count = 0;
    int str_len = 11;
    int k = 0;
    for (int k = 0; k < str_len; k++)
    {
        letter = abcs[k];
        switch (letter)
        {
        case 'a':
            a_count++;
            break;
        case 'b':
            b_count++;
            break;
        case 'c':
            c_count++;
            break;
        }
    }
    printf("\nIn the following string: %s there are \n", abcs);
    printf("a_count=%d, b_count=%d, c_count=%d\n", a_count, b_count, c_count);

    /* --------------
    -- Functions  --
    ---------------- */

    // -- printf() --
    // the printf() function is defined in the stdio.h header file
    printf("Hello world");

    // -- sizeof() -- 
    // the sizeof() function is defined in the stdlib.h header file
    printf("The size of a float is %lu bytes \n", sizeof(my_float));
    printf("The size of a int is   %lu bytes\n", sizeof(my_int));
    printf("The size of a char is  %lu bytes\n", sizeof(my_char));

    // You can use sizeof to find the length of an array
    int array_1d[] = {1, 2, 3, 4, 5, 6};
    printf("My array has length = %lu\n", sizeof(array_1d)/sizeof(array_1d[0]));

    // -- rand() --
    // the rand() function is defined in the stdlib.h header file
    // generates random numbers in the range 0 to RAND_MAX
    printf("Here is a random number: %.3f\n", (double)rand());
    printf("Here is a random number: %.3f\n", (double)rand()/(double)RAND_MAX);

    // -- strcpy() --
    // The strcpy() function is defined in the string.h header file.
    char first_name[10];
    // the statement `first_name = "Julius";` would give an error: array type 'char[10]' is not assignable
    strcpy(first_name, "Julius");
    printf("first_name=%s\n", first_name);

    /* --------------
    -- Pointers  --
    ---------------- */

    // Pointer basics
    // Holds the memory address of another variable
    // * is the indirection operator (used to declare a point as well as to get the value at address), 
    // & is the unary operator (to get the address of)

    int x = 1, y = 2, z[10];
    int *ip;    // Declaring the pointer, it has a type, it can only point to integers now.
    ip = &x;    // ip points to x (&x is a pointer to x)
    y = *ip;    // *ip gets the value of the thing ip is pointing to, in this case 1, so y is now 1.
    *ip = 0;    // x is now 0;
    ip = &z[0]; // ip is now pointing to z[0]

    int age = 21;
    int *pAge = &age;
    printf("address of age is %p\n", &age); // %p specifier to display address in hexidecimal
    printf("value of pAge is %p\n", pAge);
    printf("value of age is %d\n", age);
    printf("value at stored address is %d\n", *pAge); // dereferencing

    // Pointers and function arguments
    // Enable a function to access and change objects *within* the function that called it
    int x_coord = 3;
    int y_coord = 5;
    printf("Before swap:          x_coord=%d, y_coord=%d\n", x_coord, y_coord);
    swap_wrong(x_coord, y_coord);
    printf("After swap (wrong):   x_coord=%d, y_coord=%d\n", x_coord, y_coord);
    int *pointer_x;
    int *pointer_y;
    pointer_x = &x_coord;
    pointer_y = &y_coord;
    swap_correct(pointer_x, pointer_y);
    printf("After swap (correct): x_coord=%d, y_coord=%d\n", x_coord, y_coord);

    // Pointers and arrays
    // Close correspondence between indexing arrays and pointer arithmetic
    int my_arr[5] = {0, 1, 2, 3, 4};
    int *pa;
    pa = &my_arr[0];
    printf(" *pa     points to %d\n", *pa);
    printf(" *(pa+1) points to %d\n", *(pa+1));
    printf(" *(pa+2) points to %d\n", *(pa+2));

}