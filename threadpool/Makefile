.PHONY: a.out
a.out:
	gcc -g -c -pthread -o threadpool.o threadpool.c
	gcc -g -pthread -o extrapool extrapool.c threadpool.o
	gcc -pthread -o nopool extra.c
