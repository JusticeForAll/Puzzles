#include <stdio.h>
#include "memoryAccess.h"

int SIZE = 8;

int main()
{
	int i;
	memoryAccessEntry entries[SIZE];
	entries[0] = makeMemoryAccessEntry(1, 512, 8, READ);
    entries[1] = makeMemoryAccessEntry(2, 432, 7, WRITE);
    entries[2] = makeMemoryAccessEntry(3, 512, 6, READ);
    entries[3] = makeMemoryAccessEntry(4, 932, 5, READ);
    entries[4] = makeMemoryAccessEntry(5, 512, 4, WRITE);
    entries[5] = makeMemoryAccessEntry(6, 932, 3, READ);
    entries[6] = makeMemoryAccessEntry(7, 835, 2, READ);
    entries[7] = makeMemoryAccessEntry(8, 432, 1, READ);
	
	for(i = 0; i < SIZE; i++)
		printMemoryAccessEntry(entries[i]);
	printf("Sorting....\n\n");
	findConflicts(entries, sizeof(entries)/sizeof(entries[0]));
	
	for(i = 0; i < SIZE; i++)
		printMemoryAccessEntry(entries[i]);
	return 0;
}