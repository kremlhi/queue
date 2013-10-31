#include <stdlib.h>
#include <assert.h>
#include "queue.h"

queue_t *
queue_new(void)
{
	queue_t *queue;

	if ((queue = malloc(sizeof(queue_t))) == NULL)
		return NULL;
	queue->beg = NULL;
	queue->end = NULL;
	return queue;
}

void
queue_destroy(queue_t *queue)
{
	free(queue);
}

void *
queue_push(queue_t *queue, void *elem)
{
	qnode_t *qnode;

	assert(queue != NULL);
	if ((qnode = malloc(sizeof(qnode_t))) == NULL)
		return NULL;

	if (queue->end != NULL)
		queue->end->prev = qnode;

	if (queue->beg == NULL)
		queue->beg = qnode;

	qnode->elem = elem;
	qnode->prev = NULL;
	qnode->next = queue->end;

	queue->end = qnode;
	return qnode->elem;
}

void *
queue_pop(queue_t *queue)
{
	qnode_t *qnode;
	void *elem;

	assert(queue != NULL);
	if (queue->beg == NULL)
		return NULL;

	qnode = queue->beg;
	elem = qnode->elem;
	queue->beg = qnode->prev;
	if (queue->beg != NULL)
		queue->beg->next = NULL;
	else
		queue->end = NULL;
	free(qnode);
	return elem;
}

void *
queue_first(queue_t *queue)
{
	assert(queue != NULL);
	if (queue->beg == NULL)
		return NULL;
	return queue->beg->elem;
}

void *
queue_last(queue_t *queue)
{
	assert(queue != NULL);
	if (queue->end == NULL)
		return NULL;
	return queue->end->elem;
}

int
queue_len(queue_t *queue)
{
	int i;
	qnode_t *qnode;

	assert(queue != NULL);
	qnode = queue->beg;
	for (i = 0; qnode != NULL; i++)
		qnode = qnode->prev;
	return i;
}
