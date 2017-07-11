#include<stdlib.h>
#include<pthread.h>
struct ThreadPool
{
	
	void *(*jobs[10])(void *);
	void * arguments[10];
	void * retval[10];
	pthread_mutex_t pool_lock[10];
	pthread_cond_t pool_cond[10];
	int free[10];
	int created[10];
	pthread_t thread_id[10];
};

typedef struct arguments
{
	unsigned long int a;	
}argument;


struct ThreadID
{
	int array_id;                             //map to pool array id 
	struct ThreadPool *pool;           //every thread knows address of threadpool
	//pthread_t thread_id;               //thread id 
};

struct inrun_argument
{
	struct ThreadPool *pool;
	int array_id;
};


struct ThreadPool *pool; // Define the contents of this struct in your header file.
int ThreadPool_construct(struct ThreadPool *);
int ThreadPool_destruct(struct ThreadPool *);
//struct ThreadID; // Define the contents of this struct in your header file.
int ThreadPool_run(struct ThreadPool *, struct ThreadID *, void *(*run)(void *), void *);
//int ThreadPool_run(struct ThreadPool *, struct ThreadID *,void *);
int ThreadPool_join(struct ThreadID, void **);
void dummywork(void);
void * in_run(void*);