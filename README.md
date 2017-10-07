# Operating System Projects

1. Project 1

Goal: 
Implemented a simple version of malloc and associated functions; calloc, realloc 
and free memory block sizes were based on powers of 2. Memory was allocated using sbrk system call, free() deallocated these blocks and 
returns to my own internal list of free blocks.

Special Functionalities:
For management of memory blocks in free list; used best fit to reallocate from free-list, splitting of large blocks to allocate blocks of appropriate size for new request, merging adjacent free blocks into single contiguous block.

2. Project 2 

Goal:The objective of this project was to showcase the difference in perfomance of multithreading when using a threadpool and when creating and using threads the conventional pthreads. 10000 threads are run, each thread executes the same function for simplicity and to accurately measure the performance difference. 
TIME WITHOUT THREAD POOL: 4.476s
TIME WITH THREADPOOL: 1.596s

3. Project 3 
Goal: Xv6 system call implemented to understand the internal workings of xv6 interrupt handler and to be able to write our own system calls. 
