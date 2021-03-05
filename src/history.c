#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = NULL;
  return history_list;
}

void add_history(List *list, char *str){
  Item *listItem = malloc(sizeof(Item));
  int idCount = 0;
  if(list -> root == NULL){
    list -> root = listItem;
  }
  else{
    struct s_Item *temp = list -> root;
    idCount++;
    while(temp -> next != NULL){
      idCount++;
      temp = temp -> next;
    }
    temp -> next = listItem;
  }
  listItem -> id = idCount;
  int charCount = 0;
  while(*str != '\0'){
    charCount++;
    str++;
  }
  str = str-charCount;
  char *strCp = copy_str(str, charCount);
  listItem -> str = strCp;
  listItem -> next = NULL;
}

char *get_history(List *list, int id){
  Item *temp_node = list->root;
  while (id) {
    temp_node = temp_node->next;
    id--;
  }
  return temp_node->str;
}

void print_history(List *list){
  Item *temp_node = list->root;
  while (temp_node) {
    char *temp_str = temp_node->str;
    printf("%s\n", temp_str);
    temp_node = temp_node->next;
  }
}

void free_history(List *list){
  Item *temp_node = list->root;
  while (temp_node) {
    free(temp_node);
    temp_node = temp_node->next;
  }
  free(list);
}
