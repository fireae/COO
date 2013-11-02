#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
	int k, h, t;
	Queue *q0;
	q0 = queue_create();
	k = 100;
	for (int j = 0; j < QUEUE_SIZE; j++)
	{
		h = q0->head;
		q0->insert(q0, k);
		printf("insert %d at pos %d, size=%d", k--, h,
			q0->get_size(q0));
	}

	for (int j = 0; j < QUEUE_SIZE; j++)
	{
		t = q0->tail;
		k = q0->remove(q0);
		printf("remove %d at pos %d, size=%d\n", k, t,
			q0->get_size(q0));
	}

	return 0;
}