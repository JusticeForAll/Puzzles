#include <stdio.h>
#include "logger.h"

void printErrorMessage(const char* message)
{
    printf("***ERROR: ");
    printf("%s\n", message);
}

void printMessage(const char* message)
{
    printf("%s", message);
}