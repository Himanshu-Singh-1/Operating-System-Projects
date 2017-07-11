#include"threadpool.h"
#include<pthread.h>
#include<assert.h>
#include<stdio.h>
int ThreadPool_run(struct ThreadPool *pool, struct ThreadID *id,void *(*func)(void *),void * func_args)
{
	int rv,i=0;
	struct inrun_argument *inrun_args = malloc(sizeof(struct inrun_argument));
	//inrun_args->func_arg = (argument)func_arg;
	//rv = pthread_create(&id->thread_id,NULL,run,args);
	for(i=0;i<10;i++)
	{
		if(pool->created[i]==1)
			break ;
	}
		if(i!=0)
		{
			{
            pthread_mutexattr_t attr;
            rv = pthread_mutexattr_init(&attr); assert(rv == 0);
            rv = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK); assert(rv == 0);
            rv = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED); assert(rv == 0);
            rv = pthread_mutex_init(&pool->pool_lock[i-1], &attr); assert(rv == 0);
            rv = pthread_mutexattr_destroy(&attr); assert(rv == 0);
        }

        {
            pthread_condattr_t attr;
            rv = pthread_condattr_init(&attr); assert(rv == 0);
            rv = pthread_condattr_setpshared(&attr, PTHREAD_PROCESS_SHARED); assert(rv == 0);
            rv = pthread_cond_init(&pool->pool_cond[i-1], &attr); assert(rv == 0);
            rv = pthread_condattr_destroy(&attr); assert(rv == 0);
        }
			inrun_args->pool = pool;
			inrun_args->array_id = i-1;
			pool->created[i-1] = 1;
			pool->free[i-1]=1;
			rv = pthread_create(&pool->thread_id[i-1],NULL,&in_run,(void *)inrun_args);
		}
		for(i=0;i<10;i++)
		{
			if(pool->created[i]==1&&pool->free[i]==1)
			{
				pool->free[i] = 0;
				pool->jobs[i] = func;
				pool->arguments[i] = func_args;
				pthread_cond_signal(&pool->pool_cond[i]);
				id->array_id = i;
				id->pool = pool;
				break ;
			}
		}
	}


int ThreadPool_join(struct ThreadID id, void **arg)
{
	int rv;
	rv = pthread_mutex_lock(&id.pool->pool_lock[id.array_id]);
	
	while(id.pool->jobs[id.array_id]!=NULL)
	{
	pthread_cond_wait(&id.pool->pool_cond[id.array_id],&id.pool->pool_lock[id.array_id]);
	}
	id.pool->free[id.array_id] = 1;
	*arg = id.pool->retval[id.array_id];
	rv = pthread_mutex_unlock(&id.pool->pool_lock[id.array_id]);
	//printf("%d:%lu\n",id.array_id,*arg);	
	pthread_cond_signal(&id.pool->pool_cond[id.array_id]);
	
	//printf("%u",(int *)pool->retval[id.array_id]);
}

int ThreadPool_construct(struct ThreadPool *pool)
{
	//pool = malloc(sizeof(struct ThreadPool));
	int i=0,rv;
	if(pool==NULL)
		return 1;
	for(i=0;i<10;i++)
	{
		pool->jobs[i] = NULL;
		pool->free[i] = 0;
		pool->created[i] = 0;
		//pool->pool_lock[i] = NULL;
		//pool->pool_cond[i] = NULL;
	
	}
	
		return 0;
	
}

int ThreadPool_destruct(struct ThreadPool *pool)
{
	int i=0;
	if(pool!=NULL)
	{
		for(i=0;i<10;i++)
		{
			pool->created[i]=2;
			pthread_cond_signal(&pool->pool_cond[i]);
		}
	free(pool);
	return 1;
	}
	else
		return 0;
	
}

void * in_run(void *inargs)
{
	//printf("\nThread started\n");
	struct inrun_argument* args = (struct inrun_argument *)inargs;
	struct ThreadPool *pool = args->pool;
	int id = args->array_id;
	int rv,retval;
	while(pool->created[id]!=2)
	{
		rv = pthread_mutex_lock(&pool->pool_lock[id]);
		while(pool->jobs[id]==NULL)
		{
		rv = pthread_cond_wait(&pool->pool_cond[id],&pool->pool_lock[id]);
		if(pool->created[id]==2)
			return NULL;	
		}
		//printf("\nThread work started\n");
		pool->retval[id] = pool->jobs[id](pool->arguments[id]);
		pool->arguments[id] = NULL;
		pool->jobs[id] = NULL;
		rv = pthread_mutex_unlock(&pool->pool_lock[id]);
		pthread_cond_signal(&pool->pool_cond[id]);
	}
}

void dummywork()
{
	
}
