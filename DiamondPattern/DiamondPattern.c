#include <stdio.h>
#include <stdlib.h>

void printDiamond(const int numRows);

int main()
{
    int rowsToPrint = 0;
    printf("Enter the number of rows in the diamond: ");
    scanf("%d", &rowsToPrint);
    if(rowsToPrint < 1 || rowsToPrint % 2 == 0)
    {
        printf("Please enter an odd integer.\n");
        exit(1);
    }
    printDiamond(rowsToPrint);
    return 0;
}

void printDiamond(const int numRows)
{
    int i;
    int space = 0;
    int asterisk = 0;
    int countUp = 1;
    int numSpaces = numRows / 2;
    int numAsterisks = 1;
    
    for(i = 0; i < numRows; ++i)
    {
        for(space = 0; space < numSpaces; ++space)
        {
            printf(" ");
        }

        for(asterisk = 0; asterisk < numAsterisks; ++asterisk)
        {
            printf("*");
        }
        
        printf("\n");
        
        if(countUp)
        {
            numAsterisks += 2;
            --numSpaces;
        }
        else
        {
            numAsterisks -= 2;
            ++numSpaces;
        }
        
        if(numAsterisks == numRows)
            countUp = 0;
    }
}