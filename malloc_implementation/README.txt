-----------------------------------------------------------------------

DESCRIPTION OF PROJECT:
Implemented a simple version of malloc and associated functions; calloc, realloc 
and free memory block sizes were based on powers of 2. Memory was allocated using sbrk system call, free() deallocated these blocks and 
returns to my own internal list of free blocks. For management of memory blocks in free list;
used best fit to reallocate from free-list, splitting of large blocks to allocate blocks of appropriate size for new request, merging 
adjacent free blocks into single contiguous block.
-----------------------------------------------------------------------

Files included:
1. Makefile
2. malloc.c:
	implementation of malloc using sbrk system call.
3. test.c:
	code to run iterations foe checking the performance of malloc.
-----------------------------------------------------------------------
	
Compiling the code:
Execute make command from command line.
-----------------------------------------------------------------------

Running the code:
The main function is in test executable. Input arguments for test:
1. 0/1 flag to check for overwriting of blocks of memory.
2. number of iterations for testing 
3. number of blocks that maybe be outstanding
4. maximum block size 
-----------------------------------------------------------------------

