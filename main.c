#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {
  //create list -- aka add to heap
  printf("***Starting tests***\n");
  printf("\n***Add list to heap***\n");
  list_t *myList = list_alloc();
  
  
  //Remove from empty list? I don't think so!
  printf("\n***Removing values from empty list***\n");
  list_print(myList);
  list_remove_from_back(myList);
  list_print(myList);
  list_remove_from_front(myList);
  list_print(myList);
  list_remove_at_index(myList,-99);
  list_print(myList);
  list_remove_at_index(myList,99);
  list_print(myList);
  list_remove_at_index(myList,0);
  list_print(myList);
  list_remove_at_index(myList,1);
  list_print(myList);
  list_remove_at_index(myList,-1);
  list_print(myList);

  
  //Adding to list
  printf("\n***Adding values to list***\n");
  list_add_to_back(myList,8);
  list_print(myList);
  list_add_to_front(myList,9);
  list_print(myList);
  list_add_to_back(myList,10);
  list_print(myList);
  list_add_to_back(myList,11);
  list_print(myList);
  list_add_at_index(myList,12,0);
  list_print(myList);
  list_add_at_index(myList,13,-99);
  list_print(myList);
  list_add_at_index(myList,14,1000);
  list_print(myList);
  list_add_at_index(myList,15,5);
  list_print(myList);
  
  
  //Removing from list
  printf("\n***Removing values from list***\n");
  list_remove_from_back(myList);
  list_print(myList);
  list_remove_from_front(myList);
  list_print(myList);
  list_remove_from_back(myList);
  list_print(myList);
  list_remove_at_index(myList, -99);
  list_remove_at_index(myList, 99);
  list_remove_at_index(myList, -1);
  list_remove_at_index(myList, 1);
  list_print(myList);
  list_remove_at_index(myList, 0);
  list_print(myList);
  
  
  //Check for elements; returns 0 if not in list, 1 if it is
  printf("\n***Check for elements***\n");
  printf("%i\n",list_is_in(myList,1000));
  printf("%i\n",list_is_in(myList,-1000));
  printf("%i\n",list_is_in(myList,8));
  printf("%i\n",list_is_in(myList,9));
  printf("%i\n",list_is_in(myList,10));
  printf("%i\n",list_is_in(myList,11));
  printf("%i\n",list_is_in(myList,12));
  
  
  //Get element at an index; returns -1 if not in list
  printf("\n***Get elements at index***\n");
  list_print(myList);
  printf("Element at index %i:\t%i\n", -99, list_get_elem_at(myList, -99));
  printf("Element at index %i:\t%i\n", 99, list_get_elem_at(myList, 99));
  printf("Element at index %i:\t%i\n", -1, list_get_elem_at(myList, -1));
  printf("Element at index %i:\t%i\n", 0, list_get_elem_at(myList, 0));
  printf("Element at index %i:\t%i\n", 2, list_get_elem_at(myList, 2));
  printf("Element at index %i:\t%i\n", 3, list_get_elem_at(myList, 3));
  
  
  //Get index of element; returns -1 if not in list
  printf("\n***Get index of element***\n");
  printf("Index of %i:\t%i\n", -99, list_get_index_of(myList,-99));
  printf("Index of %i:\t%i\n", 99, list_get_index_of(myList,99));
  printf("Index of %i:\t%i\n", 8, list_get_index_of(myList,8));
  printf("Index of %i:\t%i\n", 10, list_get_index_of(myList,10));
  printf("Index of %i:\t%i\n", 15, list_get_index_of(myList,15));
  
  
  //free list from memory -- aka remove from heap
  printf("\n***Remove list from heap***\n");
  list_free(myList);
  
  printf("\n***Done with all tests***\n");
  
  //these would fail because no longer exists
  // list_print(myList);
  // free(myList);

  return 0;
}
