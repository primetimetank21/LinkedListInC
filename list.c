// list/list.c
// 
// Implementation for linked list.
//
// Earl Tankard, Jr.

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {
  list_t *newList = (list_t*) malloc(sizeof(list_t));
  return newList;
}
void list_free(list_t *l) {
  if(!l) {
    printf("No list exists!\n");
    return;
  }
  
  int nodes = 0;
  while(l->head){
    list_remove_from_front(l);
    nodes++;
  }
  
  free(l);
  printf("List freed! Deleted %d nodes\n", nodes);
}

void list_print(list_t *l) {
  //check if l is valid
  if(!l) return;
  
  printf("The list:\n");
  //check if there is a head
  //if no, return
  if(!l->head) return;
  
  //if yes, print until NULL
  node_t *cur = (node_t*) malloc(sizeof(node_t));
  cur = l->head;
  while(cur->next){
    printf("%i->", cur->value);
    cur=cur->next;
  }
  printf("%i\n", cur->value);
}
int list_length(list_t *l) { 
  //check if l is valid
  if(!l) return -1;
  
  //check if l has a head
  //if no, return 0
  if(!l->head) return 0;
  
  //if yes, traverse through list and count nodes
  node_t *cur = (node_t*) malloc(sizeof(node_t));
  cur = l->head;
  int count = 0;
  while(cur) {
    count++;
    cur=cur->next;
  }
    
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  //check if l is a valid list
  if(!l){
    return;
  }
  
  //create new node
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  
  //check if there is a head;
  //if no, make new node the head
  if(!l->head){
    l->head = newNode;
    return;
  }
  
  //if yes, traverse to last node and make the next node the new node
  node_t *tmp = l->head; 
  while(tmp->next != NULL){
    tmp=tmp->next;
  }
  
  tmp->next = newNode;
}
void list_add_to_front(list_t *l, elem value) {
  //check if l is a valid list
  if(!l) return;
  
  //create new node
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  
  //check if there is ahead;
  //if no, make new node the head
  if(!l->head) {
    l->head = newNode;
    return;
  }
  
  //if yes, make new node point to old head, then make head the new node  
  newNode->next = l->head;
  l->head = newNode;
}
void list_add_at_index(list_t *l, elem value, int index) {
  //check if l is valid
  if(!l) return;
  
  //check if there is a head
  //if not, create head
  if(!l->head) return list_add_to_front(l,value);
  
  //if index<=0, add to front
  if(index <=0) return list_add_to_front(l,value);
  
  //if index>=length of the list, add to end
  if(index>= list_length(l)) return list_add_to_back(l,value);
  
  //if the index is within the range, create node and add it in
  node_t *cur = l->head;
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  
  int i;
  for(i=0;i<index-1;i++) cur=cur->next;
  
  node_t *tmp = cur->next;
  newNode->next = cur->next;
  cur->next = newNode;
}

elem list_remove_from_back(list_t *l) {
  //check if l is valid
  if(!l) return -1;
  
  //check if head exists
  //if no, return
  if(!l->head) return -1;
  
  //if yes, traverse to 2nd to last node in the list
  node_t *cur = (node_t*) malloc(sizeof(node_t));
  cur = l->head;
  
  while(cur->next && cur->next->next) {
    cur=cur->next;
  }
  
  int popped_val;

  //if node is the head, make head point to NULL
  if(cur==l->head) {
    popped_val = l->head->value;
    l->head = NULL;
  }
  
  //if node is not the head, make the node point to NULL
  else {
    node_t *tmp = cur->next;
    free(tmp);
    popped_val = cur->next->value;
    cur->next = NULL;
  }
  
  return popped_val;
}
elem list_remove_from_front(list_t *l) {
  //check if l is valid
  if(!l) return -1;
  
  //check if head exists
  //if no, return
  if(!l->head) return -1;
  
  //if yes, make head point to next node (if it exists)
  int popped_val = l->head->value;
  node_t *tmp = l->head->next;
  free(l->head);
  l->head = tmp;
  
  return popped_val;
}
elem list_remove_at_index(list_t *l, int index) {
  //check if l is valid
  if(!l) return -1;
  
  //check if head exists
  if(!l->head) return -1;
    
  //check if index is out of range
  if(index < 0 || index >= list_length(l)) {
    printf("%i is out of range!\n",index);
    return -1;
  }
  
  //check if index is 0
  //if yes, modify head
  if(index==0) return list_remove_from_front(l);
  
  //if no, iterate to index
  node_t *cur = l->head;
  int i;
  for(i=0;i<index-1;i++) {
    cur=cur->next;
  }
  
  //if possible, delete
  //might need more cases
  if(cur) {
    node_t *tmp = cur->next;
    int popped_val = tmp->value;
    cur->next = tmp->next;
    free(tmp);
    return popped_val;
  }
  
  //if not possible, return
  printf("Sumn happened!\n");
  return -1;
}

bool list_is_in(list_t *l, elem value) {
  //check if l is valid
  if(!l) return false;
  
  //check if head exists
  if(!l->head) return false;
  
  //iterate through list and check for presence
  node_t *cur = l->head;
  while(cur) {
    if(cur->value == value) return true;
    cur=cur->next;
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) {
  //check if l is valid
  if(!l) return -1;
  
  //check if head exists
  if(!l->head) return -1;
  
  //check if index is out of range
  //if yes, return -1
  if(index < 0 || index >= list_length(l)) return -1;
   
  //if no, iterate to index
  node_t *cur = l->head;
  int i;
  for(i=0;i<index;i++) cur=cur->next;
  return cur->value;
}
int list_get_index_of(list_t *l, elem value) {
  //check if l is valid
  if(!l) return -1;
  
  //check if head exists
  if(!l->head) return -1;
    
  //iterate to value
  node_t *cur = l->head;
  int index = 0;
  while(cur && cur->value != value) {
    cur=cur->next;
    index++;
  }
  
  //if possible, return index
  if(cur) return index;
  
  return -1;
}
