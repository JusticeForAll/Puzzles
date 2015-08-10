#include <stdio.h>
#include <stdlib.h>

void printDiamond(const int numRows);

int main()
{
    int rowsToPrint = 0;
    printf("Enter the number of rows in the diamond: ");
    scanf("%d", &rowsToPrint);
    printDiamond(rowsToPrint);
    return 0;
}

void printDiamond(const int numRows)
{
    int i;
    int space = 0;
    int countUp = 1;
    int asterisk = 0;
    int numSpaces = numRows - 1;
    int numAsterisks = 1;
    
    for(i = 0; i < numRows * 2 - 1; ++i)
    {
        if(i == (numRows - 1))
            countUp = 0;

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
    }
}
