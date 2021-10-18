// list/list.c
// 
// Implementation for linked list.
//
// Teanna Barrett @02924893
// 
// Code snippets from:
// @learn-c.org https://www.learn-c.org/en/Linked_lists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  // use malloc 
  node_t *head = node_alloc();
  list_t *list = (list_t *) malloc(sizeof(list_t));
  list->head = head;
  return list;
}

void list_free(list_t *l) {
  // use free() but in a loop to go through whole list
  node_t *curr = l->head;
  free(l);
  
  while(curr->next != NULL) {
    node_free(curr);
    curr = curr->next;
  }
}

node_t *node_alloc() {
  node_t *node = NULL;
  node = (node_t *) malloc(sizeof(node_t));
  return node;
}

void node_free(node_t *n) {
  free(n);
}

void list_print(list_t *l) {
  node_t * curr = l->head;
  
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->next;
  }
}

int list_length(list_t *l) { 
  node_t *curr = l->head;
  int counter = 0;
  while (curr->next != NULL) {
    counter++;
    curr = curr->next;
  }
  return counter; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t *curr = l->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  node_t *new_node = node_alloc();
  new_node->value = value;
  curr->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *pushed_head = l->head;
  node_t *new_node = node_alloc();
  new_node->value = value;
  new_node->next = pushed_head;
  l->head = new_node; 
}
void list_add_at_index(list_t *l, elem value, int index) {
  // loop to end of list, alloc node and add node to next
  // while (curr->next != NULL)
  // exit loop then curr->next = new_node
  // new_node->next = NULL 
  // Edge cases: index out of bounds (curr != NULL, )
  // if curr= Null after (add to end)
  if (index == 0) {
    list_add_to_front(l, value);
    return;
  }
  node_t *curr = l->head;
  node_t *prev = NULL;
  int counter = 0;
  
  while (counter < index && curr != NULL) {
    counter++;
    prev = curr;
    curr = curr->next;
  }
  
  if (curr != NULL && counter == index) {
    list_add_to_back(l, value);
    return;
  }
  
  else {
    node_t *new_node = node_alloc();
    new_node->value = value;
    new_node->next = prev->next;
  }
}

elem list_remove_from_back(list_t *l) { 
  elem removed_val =  -1;
  node_t *curr = l->head;
  
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  
  removed_val = curr->next->value;
  node_free(curr->next);
  curr->next = NULL;
  
  return removed_val; 
}

elem list_remove_from_front(list_t *l) { 
  node_t *head = l->head;
  elem removed_val = head->value;
  node_t *new_head = l->head->next;
  l->head = new_head;
  return removed_val;
}

elem list_remove_at_index(list_t *l, int index) { 
  if (index == 0) {
    return list_remove_from_front(l);
  }
  
  node_t *curr = l->head;
  node_t *prev = NULL;
  int counter = 0;
  
  while (counter < index && curr->next != NULL) {
    curr = curr->next;
    counter++;
  }
  
  if (curr != NULL && counter == index) {
    return list_remove_from_back(l);
  }
  
  else {
    node_t *hold_node = curr->next;
    int removed_val = hold_node->value;
    curr->next = hold_node->next;
    node_free(hold_node);
    return removed_val;
  }
}

bool list_is_in(list_t *l, elem value) { 
  node_t *curr = l->head;
  
  while(curr->next != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  node_t *curr = l->head;
  int counter = 0;
  
  while (curr->next != NULL) {
    if (counter == index) {
      return curr->value;
    }
    curr = curr->next;
    counter++;
  }
  return -1; 
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *curr = l->head;
  int counter = 0;
  
  while (curr->next != NULL) {
    if (curr->value == value) {
      return counter;
    }
    curr = curr->next;
    counter++;
  }
  return -1; 
}

