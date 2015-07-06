#include <stdlib.h>
#include <stdio.h>
#include "memoryAccess.h"
#include "logger.h"

memoryAccessEntry makeMemoryAccessEntry(const int threadNum, const int memBlockAddress, const int zeit, const int rw)
{
    memoryAccessEntry new;
    new.threadNumber = threadNum;
    new.memoryBlockAddress = memBlockAddress;
    new.time = zeit;
    new.readWrite = rw;
    
    return new;
}

memoryAccessEntry* makeMemoryAccessEntryPtr(const int threadNum, const int memBlockAddress, const int zeit, const int rw)
{
    memoryAccessEntry* newPtr = (memoryAccessEntry*)malloc(sizeof(memoryAccessEntry));
    newPtr->threadNumber = threadNum;
    newPtr->memoryBlockAddress = memBlockAddress;
    newPtr->time = zeit;
    newPtr->readWrite = rw;
    
    return newPtr;
}

void mergeSortMemoryAccessEntries(memoryAccessEntry* arr, const int leftPosition, const int rightPosition, const int sortingParameter)
{
    if(leftPosition < rightPosition)
    {
        int middlePosition = leftPosition + (rightPosition - leftPosition) / 2;
        mergeSortMemoryAccessEntries(arr, leftPosition, middlePosition, sortingParameter);
        mergeSortMemoryAccessEntries(arr, middlePosition + 1, rightPosition, sortingParameter);
        mergeMemoryAccessEntries(arr, leftPosition, middlePosition, rightPosition, sortingParameter);
    }
}

void mergeMemoryAccessEntries(memoryAccessEntry* arr, const int leftPosition, const int middlePosition, const int rightPosition, const int sortingParameter)
{
    int i, j, k;
    int numElementsLeft = middlePosition - leftPosition + 1;
    int numElementsRight = rightPosition - middlePosition;
    
    memoryAccessEntry leftTempArr[numElementsLeft];
    memoryAccessEntry rightTempArr[numElementsRight];
    
    for(i = 0; i < numElementsLeft; i++)
        leftTempArr[i] = arr[leftPosition + i];
    for(j = 0; j < numElementsRight; j++)
        rightTempArr[j] = arr[middlePosition + j + 1];
        
    i = j = 0;
    k = leftPosition;
    
    while(i < numElementsLeft && j < numElementsRight)
    {
        BOOL comparisonResult = FALSE;
        switch(sortingParameter)
        {
            case THREAD_NUMBER:
                comparisonResult = leftTempArr[i].threadNumber <= rightTempArr[j].threadNumber;
                break;
            case MEMORY_BLOCK_ADDRESS:
                comparisonResult = leftTempArr[i].memoryBlockAddress <= rightTempArr[j].memoryBlockAddress;
                break;
            case TIME:
                comparisonResult = leftTempArr[i].time <= rightTempArr[j].time;
                break;
            case READ_WRITE:
                comparisonResult = leftTempArr[i].readWrite <= rightTempArr[j].readWrite;
                break;
            default:
                printErrorMessage("Unrecognised sort option.");
                break;
        }
        if(comparisonResult)
        {
            arr[k] = leftTempArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightTempArr[j];
            ++j;
        }
        ++k;
    }
    
    while(i < numElementsLeft)
    {
        arr[k] = leftTempArr[i];
        ++i;
        ++k;
    }
    
    while(j < numElementsRight)
    {
        arr[k] = rightTempArr[j];
        ++j;
        ++k;
    }
}

void findConflicts(memoryAccessEntry* arr, const int size)
{
    mergeSortMemoryAccessEntries(arr, 0, size-1, MEMORY_BLOCK_ADDRESS);
    
    int leftPosition = 0;
    int rightPosition = 0;
    
    while(rightPosition <= size - 1)
    {
        if(arr[leftPosition].memoryBlockAddress == arr[rightPosition].memoryBlockAddress)
        {
            if(rightPosition < size - 1)
                ++rightPosition;
            else 
            {
                mergeSortMemoryAccessEntries(arr, leftPosition, rightPosition, TIME);
                break;
            }
        }
        else
        {
            mergeSortMemoryAccessEntries(arr, leftPosition, rightPosition-1, TIME);
            leftPosition = rightPosition++;
        }
    }
    
    int i;
    for(i = 1; i < size; ++i)
    {
        if(arr[i-1].memoryBlockAddress == arr[i].memoryBlockAddress)
        {
            int j = i;
            while(j > 0 && arr[j].memoryBlockAddress == arr[i].memoryBlockAddress)
            {
                if(isConflict(arr[j], arr[i]))
                    printf("Conflict found: threads %d and %d.\n", arr[j].threadNumber, arr[i].threadNumber);
                --j;
            }
        }
    }
}

BOOL isConflict(const memoryAccessEntry arr1, const memoryAccessEntry arr2)
{
    return ((abs(arr1.time - arr2.time) <= THREAD_ACCESS_TIME_THRESHOLD) && 
            (arr1.readWrite == WRITE || arr2.readWrite == WRITE) &&
            (arr1.threadNumber != arr2.threadNumber));
}

void printMemoryAccessEntry(const memoryAccessEntry entry)
{
    printf("***Memory Access Entry:\n");
    printf("   Thread Number: %d\n", entry.threadNumber);
    printf("   Memory Block Address: %d\n", entry.memoryBlockAddress);
    printf("   Access Time: %d\n", entry.time);
    printf("   Read/Write: %s\n", entry.readWrite == READ ? "READ" : "WRITE");
    printf("***\n");
}