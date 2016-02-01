#include <stdio.h>
#include <stdlib.h>

void printMatrix(unsigned int dimension, int** matrix, unsigned int offset);
void printPattern(int** matrix, unsigned int dimension, unsigned int offset);

#define DIMENSION 3

int main()
{
    int** arr;
    int i, j;
    unsigned int count = 1;
    
    arr = malloc(DIMENSION * sizeof(int*));
    for(i = 0; i < DIMENSION; ++i)
    {
        arr[i] = malloc(DIMENSION * sizeof(int));
    }
    
    for(i = 0; i < DIMENSION; ++i)
    {
        for(j = 0; j < DIMENSION; ++j)
        {
            arr[i][j] = count++;
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

    printMatrix(DIMENSION, arr, 0);
 
    for(i = 0; i < DIMENSION; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}

void printMatrix(unsigned int dimension, int** matrix, unsigned int offset)
{
    if(dimension == 1)
    {
        printf(" %d ", *(*(matrix) + offset));
        return;
    }
    else if(dimension == 0)
        return;

    printPattern(matrix, dimension, offset);
    printMatrix(dimension-2, &(matrix[1]), ++offset);
}

void printPattern(int** matrix, unsigned int dimension, unsigned int offset)
{
    int i, j;
    //Top
    for(i = 0; i < dimension; ++i)
        printf(" %d ", *(*(matrix) + i  + offset));
    //Right column
    for(j = 1; j < dimension; ++j)
        printf(" %d ", *(*(matrix + j) + dimension - 1  + offset));
    //Bottom
    for(i = dimension - 2; i > -1; --i)
        printf(" %d ", *(*(matrix + dimension - 1) + i  + offset));
    //Left column
    for(j = dimension - 2; j > 0; --j)
        printf(" %d ", *(*(matrix + j) + offset));
}