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

/* Queue Item
 *
 * Returns a list of the elements in the queue
 * Returns NULL in the event of an error.
 */
void** queue_list(queue* queue)
{
	// Create an empty list
	void** items = (void**)malloc(sizeof(void*) * queue->size + 1);
	assert(items != NULL);
	// memset(items, 0, sizeof(items));

	// Declare variables
	qnode* current_node;
	void* current_item;

	// Initialize Values
	current_node = queue->tail;
	// current_item = current_node->data;
	*(items) = current_node;
	// NULL pointers should not be added to the list? Should they
	
	// long int i = queue->size;
	// *(items + i) = 0;

	// Works in reverse
	int i = 0;
	do
	{
		if (current_node->data == NULL)
			fprintf(stderr, "Warning: NULL node in queue.\n");
		*(items + i) = current_node->data;


		// printf("[%d]>> In list: %s, Node: %c\n", i, *(char**)(items + i), *(char*)current_node->data);
		i++;
	} while ((current_node = current_node->prev) != NULL);

	return items;
}
