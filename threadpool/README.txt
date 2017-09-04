-----------------------------------------------------------------------

## PROJECT DESCRIPTION:
The objective of this project was to showcase the difference in perfomance of multithreading when using a threadpool and when creating and using threads the conventional pthreads. 10000 threads are run, each thread executes the same function for simplicity and to accurately measure the performance difference. Two executables are created: nopool uses conventional pthreads to run these 10000 threads and extrapool uses threadpool to run the same. The difference in timing noted for one of the runs:

TIME WITHOUT THREAD POOL: 4.476s
TIME WITH THREADPOOL: 1.596s
-----------------------------------------------------------------------

## FILES INCLUDED:

1. Makefile
2. extrapool.c:
	Has main loop runs 10000 threads using conventional pthreads not using threadpool
	its executable is created as nopool.
3. extra.c:
	Contains main loop that runs 10000 threads using threapool its executable
	is created as extrapool.
4. threadpool.c:
	contains the implementation of threadpool has implementation of following functions
	for threadpool:
	ThreadPool_run
	ThreadPool_join
	ThreadPool_construct
	ThreadPool_destruct
5. threadpool.h:
	contains the header file with threadpool function declarations, structures used for
	creating pool and definition of function run by each thread.

6. pool_timing.png:
	Image showing the time taken for running 10000 threads using threadpool and 
	and by using conventional pthreads.
-----------------------------------------------------------------------	

## FUNCTION IMPLEMENTED BY THREADS: 
function name: func
argument: of type struct argument has only one int memeber a.
function: increments a by one.
return: returns a pointer to a.
-----------------------------------------------------------------------

## MAIN FILES:

1. extra.c:	this is implementation has no threadpool, thread creation and joining is done by the p_thread library.
	Main loop:
	1. Create an array of structure arguments of size 10, one argument for each thread.
	2. Loop runs 10000 times.

	two loops inside main big loop:
	3. each time loop creates 10 threads with func as the function and argument structure as argument .
	4. another loop joins each thread and adds the returned value to global count.
	5. Value of count is checked at each run, to be equal.


2. extrapool.c:

	ThreadPool data strucuture:
	1. Only 10 thread are present inside the thread pool data structure.
	2. An array of 10 locks for each thread.
	3. An array of 10 conditional variables.
	4. An array of 10 jobs which will have the func function only.
	5. Loop runs 10000 times each time it creates thread using the threadpool api implemented
		in threadpool.c
	6. Both loops on extra and extrapool.c run exactly the same way but extrapool.c uses the threadpool
		api for creation and joining.
-----------------------------------------------------------------------

Running code:
execute make command
creates nopool executable for implementation with no threadpool
creates extrapool executable for implementation with threadpool
-----------------------------------------------------------------------
