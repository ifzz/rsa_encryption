#ifndef QUEUE_T
#define QUEUE_T
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/* Queue
 * File: queue.h
 * Auth: Evan Wilde <etcwilde@uvic.ca>
 * Date: March-28-2014
 */

/* Node structure */

typedef struct _qnode 
{
	struct _qnode* next;
	struct _qnode* prev;
	void* data;
} qnode;


/* queue structure */

typedef struct _queue 
{
	size_t size;
	qnode* head;
	qnode* tail;
} queue;

/* Queue Initialize
 *
 * Initializes queue
 * Complexity: O(1)
 */
queue* queue_init(void);

/* Queue Push
 *
 * Add element to queue
 * Complexity: O(1)
 */
void queue_push(queue* queue, void* data);

/* Queue Pop
 *
 * Remove element from queue
 * Complexity: O(1)
 */
void* queue_pop(queue* queue);

/* Queue Size
 *
 * Returns the size of the queue
 * Complexity: O(1)
 */
size_t queue_size(queue* queue);

/* Queue Free
 *
 * Frees all elements in a queue and the queue itself 
 * Complexity: O(n)
 */
void queue_free(queue* queue);

/* Queue Peek
 *
 * Allows us to look at element in the queue without removing the node 
 * Complexity: O(1)
 */
inline void* queue_peek(queue* queue);

#endif
