/* Prototype of the vPortGetHeapStats() function. */
void vPortGetHeapStats( HeapStats_t *xHeapStats );

/* Definition of the Heap_stats_t structure. */
typedef struct xHeapStats
{
	size_t xAvailableHeapSpaceInBytes;      /* The total heap size currently available - this is the sum of all the free blocks, not the largest block that can be allocated. */
	size_t xSizeOfLargestFreeBlockInBytes; 	/* The maximum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats() is called. */
	size_t xSizeOfSmallestFreeBlockInBytes; /* The minimum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats() is called. */
	size_t xNumberOfFreeBlocks;		/* The number of free memory blocks within the heap at the time vPortGetHeapStats() is called. */
	size_t xMinimumEverFreeBytesRemaining;	/* The minimum amount of total free memory (sum of all free blocks) there has been in the heap since the system booted. */
	size_t xNumberOfSuccessfulAllocations;	/* The number of calls to pvPortMalloc() that have returned a valid memory block. */
	size_t xNumberOfSuccessfulFrees;	/* The number of calls to vPortFree() that has successfully freed a block of memory. */
} HeapStats_t;




/* Allocate two blocks of RAM for use by the heap.  The first is a block of
0x10000 bytes starting from address 0x80000000, and the second a block of
0xa0000 bytes starting from address 0x90000000.  The block starting at
0x80000000 has the lower start address so appears in the array fist. */
const HeapRegion_t xHeapRegions[] =
{
    { ( uint8_t * ) 0x80000000UL, 0x10000 },
    { ( uint8_t * ) 0x90000000UL, 0xa0000 },
    { NULL, 0 } /* Terminates the array. */
};

/* Pass the array into vPortDefineHeapRegions(). */
vPortDefineHeapRegions( xHeapRegions );