#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Make any use of assert in dbg_print() go away, unless we are actually just testing
// dbg_print().  In that case, define DBG_PRINT_TEST.
#ifndef DBG_PRINT_TEST
#define NDEBUG
#endif
#include <assert.h>
//#include "test.c"
/*
static void
error() {
    const char *const m = "\ndbg_print(): Bad format.\n";
    write(2, m, strlen(m));
}
*/    //error commented out to use error of test.c file 
//void printheap();
/*
static char *
ultoa_helper(char *buf, unsigned long ul) {
    if (ul > 0) {
        buf = ultoa_helper(buf, ul/10);
        *buf++ = '0' + ul%10;
    }
    return buf;
}
*/

// Convert ulong to ASCII.
/*
static void
ultoa(char *buf, unsigned long ul) {
    assert(buf != 0);
  size_t powerof2(size_t n)
  {
  size_t count =0;
  if(n && !(n&(n-1)))
  return n;
  while(n!=0)
  {
 n >>=1;
 count +=1;
 }
  return 1 << count;
 }  if (ul == 0) {
        *buf++ = '0';
    } else {
        buf = ultoa_helper(buf, ul);
    }
    *buf = '\0';
}
*/
// Push diag context so we can ignore unused vars.
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
/*
// This is a tiny version of printf() that accepts only %lu and %%.
void
dbg_print(const char *fmt, ...) {

    enum { ST_CHUNK = 1, ST_PERCENT, ST_L } state = ST_CHUNK;
    size_t chunk_begin = 0;
    int ec;

    va_list ap;
    va_start(ap, fmt);

    size_t i = 0;
    for (; fmt[i] != '\0'; i++) {
        int ch = fmt[i];
        switch (state) {
            case ST_CHUNK:
                {
                    if (ch == '%') {
                        state = ST_PERCENT;
                        ec = write(2, &fmt[chunk_begin], i - chunk_begin);
                        assert((unsigned) ec == i - chunk_begin);
                    }
                }
                break;
            case ST_PERCENT:
                {
                    if (ch == 'l') {
                        state = ST_L;
                    } else if (ch == '%') {
                        chunk_begin = i;
                        state = ST_CHUNK;
                    } else {
                        error();
                    }
                }
                break;
            case ST_L:
                {
                    if (ch == 'u') {
                        unsigned long ul = va_arg(ap, unsigned long);
                        char buf[100];
                        ultoa(buf, ul);
                        ec = write(2, buf, strlen(buf));
                        assert((unsigned) ec == strlen(buf));
                        chunk_begin = i + 1;
                        state = ST_CHUNK;
                    } else {
                        error();
                    }
                }
                break;
            default:
                assert(0);
                abort();
                break;
        }
    }

    if (i - chunk_begin > 0) {
        ec = write(2, &fmt[chunk_begin], i - chunk_begin);
        assert((unsigned) ec == i - chunk_begin);
    }

    va_end(ap);
}
*/
#pragma GCC diagnostic pop

typedef struct Block {
    size_t size;
    struct Block *next;
    struct Block *prev;
} block_t;
size_t powerof2(size_t);  //Power of 2 function
void fragment(block_t *,size_t);
static block_t *head;

void *
malloc(size_t sz) {        

    //char msg_buf[100];
    size_t powerofsz = powerof2(sz + sizeof(block_t));
    block_t **bpp;
    for (bpp = &head; *bpp != 0; bpp = &(*bpp)->next) {
        if ((*bpp)->size >= sz) {
            block_t *found = *bpp;

		if(found == head)
		{
			head = found->next;
			if(found->next != NULL)
			head->prev = NULL;
		}

		else
		{
			if(found->prev == NULL)
			//printheap();
			found->prev->next = found->next;
			if(found->next != NULL)
			found->next->prev = found->prev;
		}


        if((found->size + sizeof(block_t)) > powerofsz)
        {
			fragment(found,sz);
        }
        void *vp = (char *) found + sizeof(block_t); // Skip past size that we saved. Changed size_t to sizeof(block_t)
           //sprintf(msg_buf, ">>> Reallocated %zu bytes for %zu byte request at %p.\n", found->size, sz, vp);
            //write(2, msg_buf, strlen(msg_buf));
        return vp;
        }
    }

    // If reached, need to allocate another block.  It cannot
    // be smaller than the amount of space we need for bookkeeping.
    // ASK size_t sb_req = sz + sizeof(size_t); // Total amount needed based on caller req.
    size_t sb_req = sz + sizeof(block_t); //Code changed 
    // Make sure that it's big enough to hold a Block.
    sb_req = powerof2(sb_req);
    sb_req = sb_req < sizeof(block_t) ? sizeof(block_t) : sb_req;  //ASK 
    block_t *new_block = (block_t *) sbrk(sb_req);
    // More available than sz if sz was very small.
    //new_block->size = sb_req - sizeof(size_t); ASK
    new_block->size = sb_req - sizeof(block_t);

    //ASK void *vp = (char *) new_block + sizeof(size_t);
    void *vp = (char *) new_block + sizeof(block_t);
    //sprintf(msg_buf, ">>> Allocated %zu new bytes for %zu byte request at %p.\n", new_block->size, sz, vp);
    //write(2, msg_buf, strlen(msg_buf));

    return vp;
}
void fusion(block_t *);

void
free(void *vp) {

    /*
    {
        char msg_buf[100];
        sprintf(msg_buf, "Freeing at %p...\n", vp);
        write(2, msg_buf, strlen(msg_buf));
    }
    */

    if (vp != 0) {

		block_t *bp = (block_t *) (((char *) vp) - sizeof(block_t)); //Changed from size_t to block_t      
		if(head == NULL)
		{
			head = bp;
			bp->next = NULL;
			bp->prev = NULL;
			return;
		} 
		else
		{
		block_t *ptr = head;
			while(ptr->next!=NULL)
			{
				if(bp<ptr)
				{
					if(ptr!=head)
					{
						bp->next = ptr;
						bp->prev = ptr->prev;
						if(ptr->prev!=NULL)
							ptr->prev->next = bp;
							ptr->prev = bp;	
					}
					else
					{
						bp->next = ptr;
						bp->prev = NULL;
						ptr->prev = bp;              //Current change
						head = bp;
					}
					fusion(bp);
					return;
				}
				ptr = ptr->next;
			} 
		ptr->next = bp;
		bp->next = NULL;
		bp->prev = ptr;    
		}
		fusion(bp);        //fusion of freed block after it has been placed in right position in free list. 
	}
		//dbg_print("<<< Freed %lu bytes at %lu...\n", bp->size, vp);
}        




void fusion(block_t *ptr)
{
	if((ptr->next!=NULL) && (ptr ==(block_t*)((char *)ptr->next - ptr->size - sizeof(block_t))) && (ptr->size == ptr->next->size) )
	{
		ptr->size = ptr->size + ptr->next->size + sizeof(block_t);
		if(ptr->next->next!=NULL)
			ptr->next->next->prev = ptr;
	ptr->next = ptr->next->next;
	fusion(ptr);
	return;
	}
	if((ptr->prev!=NULL) && (ptr ==(block_t*)((char*)ptr->prev + ptr->prev->size + sizeof(block_t))) && (ptr->size == ptr->prev->size))
	{
	ptr->prev->size = ptr->prev->size + ptr->size + sizeof(block_t);
	ptr->prev->next = ptr->next;
		if(ptr->next!=NULL)
			ptr->next->prev = ptr->prev;
	fusion(ptr);
	return;
	}
}


void fragment(block_t *found, size_t sz)
{
	
	int sizeofbigblock = found->size + sizeof(block_t);
	int sizerequired = powerof2(sizeof(block_t)+sz);
	int sizetmp=sizerequired;
	found->size = sizerequired - sizeof(block_t);

//Delinking found block here insted of in malloc to handle the fusion just after fragmentation
/*
if(found == head)
 {
 head = found->next;
if(found->next != NULL)
 head->prev = NULL;
 }
 else
 {
 found->prev->next = found->next;
 if(found->next != NULL)
 found->next->prev = found->prev;
 }
*/

	block_t *tmp;
	//block_t *ptr=found;

	while(sizetmp<sizeofbigblock)
	{
		tmp =(block_t *)((char *)found + sizetmp);
		tmp->size = sizetmp - sizeof(block_t);
		free((void *)((char *)tmp+ sizeof(block_t)));
		//ptr->next = tmp;
		sizetmp =sizetmp*2;
		//ptr=ptr->next;
	}
}




void *realloc(void *ptr, size_t size)
{
	if(!ptr)
	return malloc(size);  //Realloc with null ptr should act like malloc.

	block_t *bp = (block_t *)(((char *)ptr)- sizeof(block_t));
	void *new_ptr; 
	new_ptr = malloc(size);
	if(!new_ptr)
		return NULL; //error in allocating dynamic memory via malloc
	if(bp->size<size)
		memcpy(new_ptr, ptr, bp->size);
	else
		memcpy(new_ptr,ptr,size);
	free(ptr);
	return new_ptr;
}



void *calloc(size_t num1, size_t num2)
{
size_t size = num1*num2;
void *ptr = malloc(size);
memset(ptr,0,size);
return ptr;
}

size_t powerof2(size_t n)
{
	size_t count =0;
	if(n && !(n&(n-1)))
		return n;
	while(n!=0)
	{
		n >>=1;
		count +=1;
	}
	return (1 << count);
 }
/*
void printheap()
{
block_t *ptr = head;
while(ptr!=NULL)
{
printf("\nprev: %p  current: %p  next: %p", ptr->prev,ptr,ptr->next);
ptr=ptr->next;
}
}
*/
/*
int main() {

    malloc(1);
    void *ptr = malloc(100);
    void *str = malloc(50);
    free(ptr);
    free(str);
    ptr= malloc(20);
    heapprint();
    return 0;
}
*/  //commented to use main of test.c file

