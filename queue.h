#ifndef __QUEUE_H__
# define __QUEUE_H__

typedef struct qnode_t qnode_t;
typedef struct queue_t queue_t;

struct qnode_t {
	qnode_t *next, *prev;
	void *elem;
};

struct queue_t {
	qnode_t *beg, *end;
};

queue_t *queue_new(void);
void queue_destroy(queue_t *);
void *queue_push(queue_t *, void *);
void *queue_pop(queue_t *);
void *queue_first(queue_t *);
void *queue_last(queue_t *);
int queue_len(queue_t *);

#endif
