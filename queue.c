#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue *const me, 
	int (*is_full_func)(Queue *const me),
	int (*is_empty_func)(Queue *const me),
	int (*get_size_func)(Queue *const me),
	void (*insert_func)(Queue *const me, int k),
	int (*remove_func)(Queue *const me))
{
	me->head = 0;
	me->size = 0;
	me->tail = 0;
	me->is_full = is_full_func;
	me->is_empty = is_empty_func;
	me->get_size = get_size_func;
	me->insert = insert_func;
	me->remove = remove_func;
}

void queue_cleanup()
{}

int queue_is_full(Queue *const me)
{
	return (me->head + 1) % QUEUE_SIZE == me->tail;
}

int queue_is_empty(Queue *const me)
{
	return (me->head == me->tail);
}

int queue_get_size(Queue *const me)
{
	return me->size;
}

void queue_insert(Queue *const me, int k)
{
	if (!me->is_full(me))
	{
		me->buffer[me->head] = k;
		me->head = (me->head + 1) % QUEUE_SIZE;
		++ me->size;
	}
}

int queue_remove(Queue *const me)
{
	int value = -9999;
	if (!me->is_empty(me))
	{
		value = me->buffer[me->tail];
		me->tail = (me->tail + 1) % QUEUE_SIZE;
		-- me->size;
	}
	return value;
}

Queue *queue_create(void)
{
	Queue *me = (Queue *)malloc(sizeof(Queue));
	if (NULL != me)
	{
		queue_init(me, queue_is_full, queue_is_empty,
			queue_get_size, queue_insert, queue_remove);
	}
	return me;
}	

void queue_destroy(Queue *const me)
{
	if (NULL != me)
	{
		queue_cleanup(me);
	}
	free(me);
}