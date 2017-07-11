#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<assert.h>
#include<unistd.h>
#include<time.h>
#include"threadpool.h"
#define MAX_T 10


void* func(void *inargs)
{
	argument *args = (argument*)inargs;
	args->a ++;
	//printf("\nIn func");
	//printf("%lu",args->a);
	return (void *)args->a;
}


int main()
{
	struct ThreadPool *pool = malloc(sizeof(struct ThreadPool));
	pthread_t p[MAX_T];
	int rv,i=0,j=0;
	unsigned long int counter = 0;
	argument newarg[MAX_T];
	
	for(i=0;i<MAX_T;i++)
	{
		newarg[i].a = 0;
	}
	//rv = ThreadPool_construct(pool);
	for(j=0;j<1000;j++)
	{
	for(i=0;i<MAX_T;i++)
		//ThreadPool_run(pool,&p[i],&func,&newarg[i]);
		rv = pthread_create(&p[i],NULL,func,&newarg[i]);
		for(i=0;i<MAX_T;i++)
		{
			int ret;
			//ThreadPool_join(p[i],(void **)&ret);
			pthread_join(p[i],(void **)&ret);
			counter+=ret;
		}
	}
	//rv = ThreadPool_destruct(pool);
	printf("\n***** %lu****\n",counter);
	return 0 ;

}
