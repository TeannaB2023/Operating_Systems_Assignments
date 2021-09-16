#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  // List Allocation
  list_t *new_list = list_alloc();
  printf("This is points to the head with the value of: %d \n", new_list->head->value);
  
  // List Deallocation
  
  // Print List
  
  // List Length
  
  // Add List (Front, Back, at Index)
  
  // Remove List (Front, Back, at Index)
  
  // In List
  
  // Get Element
  
  // Get Index
  return 0;
}
