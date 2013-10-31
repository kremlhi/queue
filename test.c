#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "queue.h"

int
main(int argc, char *argv[])
{
	queue_t *queue;
	char *elem;
	int i;

	if ((queue = queue_new()) == NULL)
		err(1, "queue_new");

	printf("len = %d\n", queue_len(queue));
	for (i = 1; i < argc; i++) {
		printf("+%s\n", argv[i]);
		queue_push(queue, argv[i]);
	}
	printf("len = %d\n", queue_len(queue));
	i /= 2;
	for (; i > 0 && (elem = queue_pop(queue)) != NULL; i--)
		printf("-%s\n", elem);
	printf("len = %d\n", queue_len(queue));

	for (i = 1; i < argc; i++) {
		printf("+%s\n", argv[i]);
		queue_push(queue, argv[i]);
	}
	printf("len = %d\n", queue_len(queue));

	for (; (elem = queue_pop(queue)) != NULL; )
		printf("-%s\n", elem);
	printf("len = %d\n", queue_len(queue));
	queue_destroy(queue);

	return 0;
}
