#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_SIZE 10

typedef struct Queue Queue;

struct Queue {
	int buffer[QUEUE_SIZE];
	int head;
	int size;
	int tail;
	int (*is_full)(Queue *const me);
	int (*is_empty)(Queue *const me);
	int (*get_size)(Queue *const me);
	void (*insert)(Queue *const me, int k);
	int (*remove)(Queue *const me);
	
};

void queue_init(Queue *const me, 
	int (*is_full_func)(Queue *const me),
	int (*is_empty_func)(Queue *const me),
	int (*get_size_func)(Queue *const me),
	void (*insert_func)(Queue *const me),
	int (*remove_func)(Queue *const me));
void queue_cleanup(Queue *const me);

int queue_is_full(Queue *const me);
int queue_is_empty(Queue *const me);
int queue_get_size(Queue *const me);
int queue_insert(Queue *const me, int k);
int queue_remove(Queue *const me);

Queue *queue_create(void);
void queue_destroy(Queue *const me);

#endif /* _QUEUE_H */