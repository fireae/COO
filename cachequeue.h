#ifndef _CACHE_QUEUE_H
#define _CACHE_QUEUE_H
#include "queue.h"

typedef struct CacheQueue CacheQueue;

struct CacheQueeu{
	Queue* queue;

	char filename[80];
	int numElements;

	Queue *output_queue;

	/* inherited virtual functions */
	int (*is_full)(CacheQueue *const me);
	int (*is_empty)(CacheQueue *const me);
	int (*get_size)(CacheQueue *const me);
	void (*insert)(CacheQueue *const me, int k);
	int (*remove)(CacheQueue *const me);

	/* new virtual functions */
	void (*flush)(CacheQueue *const me);
	void (*load)(CacheQueue *const me);

};

/* Operations */
int CacheQueue_is_full(CacheQueue *const me);
int CacheQueue_is_empty(CacheQueue *const me);
int CacheQueue_get_size(CacheQueue *const me);
void CacheQueue_insert(CacheQueue *const me, int k);
int CacheQueue_remove(CacheQueue *const me);

void CacheQueue_flush(CacheQueue *const me);
void CacheQueue_load(CacheQueue *const me);

CacheQueue *CacheQueue_create(void);
void CacheQueue_destroy(CacheQueue *const me);
#endif /* _CACHE_QUEUE_H */