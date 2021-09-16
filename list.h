// list/list.h
// 
// Interface definition for linked list.
//
// <Author>

#include <stdbool.h>

/* Defines the type of the elements in the linked list. You may change this if
 * you want! */
typedef int elem;

/* Defines the node structure. Each node contains its element, and points to the
 * next node in the list. The last element in the list should have NULL as its
 * next pointer. */
struct node {
	elem value;
	struct node *next;
};
typedef struct node node_t;

/* Defines the list structure, which simply points to the first node in the
 * list. */
struct list {
	node_t *head;
};
typedef struct list list_t;

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc();
// use malloc 
void list_free(list_t *l);
// use free list 
// then free each node 

node_t *node_alloc();
// use malloc for single node
void node_free(node_t *n);
// use free for node (use in list_free too)

/* Prints the list in some format. */
void list_print(list_t *l);
// loop through list and print out value of each node

/* Returns the length of the list. */
int list_length(list_t *l);
// loop through list with counter var

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value);
// loop to end of list, alloc node and add node to next
// while (curr->next != NULL)
// exit loop then curr->next = new_node
// new_node->next = NULL 
void list_add_to_front(list_t *l, elem value);
// make new node (with malloc) and next points to head
// then point list_t to new_node
void list_add_at_index(list_t *l, elem value, int index);
// if 0 list add to front
// else loop through with counter
// when at right index, next_node = curr->next
// curr->next = new_node
// new_node->next = next_node

/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l);
// loop to end of list, free node

elem list_remove_from_front(list_t *l);
// removed_elem = l->head->val
// l->head = head->next
elem list_remove_at_index(list_t *l, int index);
// loop through til at right index
// prev_node = curr
// curr = curr->next
// next_node = curr->next
// curr->next = curr->next->next
// removed_elem = next_node->val, then free

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value);
// loop through list til curr->val == value, then return true
// if loop is done return false

/* Returns the element at the given index. */
elem list_get_elem_at(list_t *l, int index);
// loop through list with counter til counter == index
// then return curr->val

/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *l, elem value);
// loop through list (with counter) til curr->val == value
// then return counter val
// if not in list return -1
