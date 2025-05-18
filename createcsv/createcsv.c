// generate random data and write to csv
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nrows = 10;
    int val1;
    float val2;
    float val3;
    char * val4;
    char * animals[] = {"cat", "dog", "snake", "rabbit", "dragon"};
    srand(time(NULL));

    // open file
    FILE *file = fopen("sampledata.csv", "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }
    
    // write csv header
    fprintf(file, "%s,%s,%s,%s\n", "col1", "col2", "col3", "col4");

    // generate and write random data
    for (int i = 0; i<nrows; i++)
    {
        val1 = rand() % 100; // int between 0 and 99
        val2 = (float)rand() / (float)RAND_MAX; // float between 0 and 1
        val3 = (float)(rand() % 3) + (float)rand() / (float)RAND_MAX;  // float between 0 and 3
        val4 = animals[rand() % 5]; // animal from the array

        fprintf(file, "%i,%.4f,%.4f,%s\n", val1, val2, val3, val4);
    }

    // close file
    if (fclose(file) != 0)
    {
        perror("Failed to close file");
        return 1;
    };
    return 0;
}