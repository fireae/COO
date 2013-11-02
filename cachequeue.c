#include "cachequeue.h"
#include <stdio.h>
#include <stdlib.h>

void CacheQueue_init(CacheQueue *const me, char *fName
	int (*isFullFunc)(CacheQueue *const me),
	int (*isEmptyFunc)(CacheQueue *const me),
	int (*getSizeFunc)(CacheQueue *const me),
	void (*insertFunc)(CacheQueue *const me, int k),
	int (*removeFunc)(CacheQueue *const me),
	void (*flushFunc)(CacheQueue *const me),
	void (*loadFunc)(CacheQueue *const me))
{
	me->queue = queue_create();
	me->numElements = 0;
	strcpy(me->filename, fName);
	me->output_queue = queue_create();

	me->is_full = isFullFunc;
	me->is_empty = isEmptyFunc;
	me->get_size = getSizeFunc;
	me->insert = insertFunc;
	me->remove = removeFunc;
	me->flush = flushFunc;
	me->load = loadFunc;
}

void CacheQueue_cleanup(CacheQueue *const me)
{
	queue_cleanup(me->queue);
}

int CacheQueue_is_full(CacheQueue *const me)
{
	return me->queue->is_full(me->queue) &&
		me->output_queue->is_full(me->output_queue);

}

int CacheQueue_is_empty(CacheQueue *const me)
{
	return me->queue->is_empty(me->queue) &&
		me->output_queue->is_empty(me->output_queue);
}

int CacheQueue_get_size(CacheQueue *const me)
{
	return me->queue->get_size(me->queue) + 
		me->output_queue->get_size(me->output_queue) +
		me->numElements;
}

void CacheQueue_insert(CacheQueue *const me, int k)
{
	if (me->queue->is_full(me->queue))
		me->flush(me);
	me->queue->insert(me->queue, k);
}

int CacheQueue_remove(CacheQueue *const me)
{
	if (!me->output_queue->is_empty(me->output_queue))
		return me->output_queue->remove(me->output_queue);
	else if (me->numElements > 0)
	{
		me->load(me);
		return me->queue->remove(me->queue);
	}
	else
		return me->queue->remove(me->queue);

}

void CacheQueue_flush(CacheQueue *const me)
{
	/* TODO */
}

void CacheQueue_load(CacheQueue *const me)
{
	/* TODO */
}

CacheQueue *CacheQueue_create(void)
{
	CacheQueue *me = (CacheQueue *)malloc(sizeof(CacheQueue));
	if (NULL != me)
	{
		CacheQueue_init(me, "a.txt",
			CacheQueue_is_full, 
			CacheQueue_is_empty,
			CacheQueue_get_size,
			CacheQueue_insert,
			CacheQueue_remove,
			CacheQueue_flush,
			CacheQueue_load);
	}

	return me;
}

void CacheQueue_destroy(CacheQueue *const me)
{
	if (NULL != me)
	{
		CacheQueue_cleanup(me);
	}
	free(me);
}