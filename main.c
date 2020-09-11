#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {
  //create list -- aka add to heap
  list_t *myList = list_alloc();
  list_add_to_back(myList,8);
  list_add_to_back(myList,9);
  list_add_to_back(myList,10);
  list_add_to_back(myList,11);
  list_print(myList);  

//   list_remove_from_back(myList);
//   list_print(myList);

  //free list from memory -- aka remove from heap
  list_free(myList);
  
  //these would fail because no longer exists
  // list_print(myList);
  // free(myList);

  return 0;
}
