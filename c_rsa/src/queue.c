#include "queue.h"
/* Queue
 * File: queue.c
 * Auth: Evan Wilde <etcwilde@uvic.ca>
 * Date: March-28-2014
 */


/* Queue Initialize
 *
 * Initializes queue
 * Complexity: O(1)
 */
queue* queue_init(void)
{
	queue* new_queue = (queue*)malloc(sizeof(queue));
	assert(new_queue != NULL);
	memset(new_queue, 0, sizeof(queue));
	return new_queue;
}

/* Queue Push
 *
 * Add element to queue
 * Complexity: O(1)
 */
void queue_push(queue* queue, void* data)
{
	qnode* new_node = (qnode*)malloc(sizeof(qnode));
	assert(new_node != NULL);
	memset(new_node, 0, sizeof(qnode));
	new_node->data = data;
	/* Empty queue */
	if (queue->size == 0)
	{
		queue->head = new_node;
		queue->tail = new_node;
	}
	else
	{
		new_node->next = queue->head;
		queue->head->prev = new_node;
		queue->head = new_node;
	}
	queue->size++;
}

/* Queue Pop
 *
 * Remove element from queue
 * Complexity: O(1)
 */
void* queue_pop(queue* queue)
{
	if (queue->size == 0) return NULL;
	void* data = queue->tail->data;
	qnode* removed_node = queue->tail;
	queue->tail = removed_node->prev;
    if (queue->tail == NULL)
        queue->head = NULL;
    else
    {
        queue->tail->next = NULL;
    }
	free(removed_node);
	queue->size--;
	return data;
}

/* Queue Size
 *
 * Returns the size of the queue
 * Complexity: O(1)
 */
size_t queue_size(queue* queue) { return queue->size; }

/* Queue Free
 *
 * Frees all elements in a queue and the queue itself 
 * Complexity: O(n)
 */
void queue_free(queue* queue)
{
	void* data;
	while (queue->size > 0)
	{
		data = queue_pop(queue);
		free(data);
	}
}

/* Queue Peek
 *
 * Allows us to look at element in the queue without removing the node 
 * Complexity: O(1)
 */
inline void* queue_peek(queue* queue)
{
	if (queue->size > 0) return queue->tail->data;
	return NULL;
}
