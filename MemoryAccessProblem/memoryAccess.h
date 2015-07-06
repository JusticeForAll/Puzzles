#define READ 0
#define WRITE 1

#define THREAD_NUMBER 2
#define MEMORY_BLOCK_ADDRESS 3
#define TIME 4
#define READ_WRITE 5

#define THREAD_ACCESS_TIME_THRESHOLD 5

typedef enum boolean
{
    FALSE,
    TRUE
} BOOL;

typedef struct 
{
    int threadNumber;
    int memoryBlockAddress;
    int time;
    int readWrite;
} memoryAccessEntry;

extern memoryAccessEntry makeMemoryAccessEntry(const int threadNum, const int memBlockAddress, const int zeit, const int rw);
extern memoryAccessEntry* makeMemoryAccessEntryPtr(const int threadNum, const int memBlockAddress, const int zeit, const int rw);

extern void mergeSortMemoryAccessEntries(memoryAccessEntry* arr, const int leftPosition, const int rightPosition, const int sortingParameter);
extern void mergeMemoryAccessEntries(memoryAccessEntry* arr, const int leftPostion, const int middlePosition, const int rightPosition, const int sortingParameter);

extern void printMemoryAccessEntry(memoryAccessEntry entry);

extern void findConflicts(memoryAccessEntry* arr, int size);
extern BOOL isConflict(memoryAccessEntry arr1, memoryAccessEntry arr2);