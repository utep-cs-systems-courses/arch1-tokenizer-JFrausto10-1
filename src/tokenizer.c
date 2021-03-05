#include "tokenizer.h"//header for this lab
#include <stdio.h>// std library
#include <stdlib.h>//i only use this for NULL macro

/*findsif a char is a space char*/
int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

/*finds if a char is a non space char*/
int non_space_char(char c){
  if(c != '\t' &&  c != ' '){
    return 1;
  }
  return 0;
}

/*finds the first char after the first white space*/
char *word_start(char *str){
  if(str[0] == '\0'){
    return str;
  }
  int index = 0;
  for(int i=0; str[i] != ' '; i++){
    if(str[i+1] == '\0'){
      return ++str;
    }
    index++;
  }
  str += (index+1);
  return str;
}

/*finds the first whitespace*/
char *word_terminator(char *str){
  if(str[0] == '\0'){
    return str;
  }
  int index = 0;
  for(int i=0; non_space_char(str[i]) == 1 ; i++){
    index++;
  }
  return str+index;
}

/*counts the amount of words in a string*/
int count_words(char *str){
  if(str[0] == '\0'){
    return 0;
  }
  int counter = 1;
  for(int i=0; str[i] != '\0'; i++){
    if(str[i] == ' '){
      counter++;
    }
  }
  return counter;
}

/*coppies strings to other places in memory and allocates memory for it*/
char *copy_str(char *instr, short len){
  char* newstr;
  newstr = malloc(sizeof(char)*(len+1));
  for(int i=0; i < len; i++){
    newstr[i] = instr[i];
  }
  newstr[len] = '\0';
  return newstr;
}

/*tokenized the given string*/
char** tokenize(char* str){
  int size_of_string = count_words(str);
  char** tokenizer = malloc(sizeof(char)*(size_of_string +1));
  char* wordEnd = word_terminator(str);
  int word_len = wordEnd - str;
  tokenizer[0] = copy_str(str, word_len);
  int count = 1;
  char* wordStart;
  while(count < size_of_string){
    wordStart = word_start(wordEnd);
    wordEnd = word_terminator(wordEnd);
    word_len = wordEnd-wordStart;
    tokenizer[count] = copy_str(wordStart, word_len);
    count++;
  }
  tokenizer[count] = '\0';
  return tokenizer;
}

/*prints the tokenize*
void print_tokens(char** tokens){
  for(int i=0; tokens[i] != NULL; i++){
    for(int j=0; tokens[i][j] != '\0'; j++){
      printf("%c", tokens[i][j]);
    }
    printf("\n");
  }
}
*/

void print_tokens(char **tokens){
  int index = 0;
  while(tokens[index] != NULL){
    printf("%s\n", tokens[index]);
    index++;
  }
}



/*frees all allocated memory*/
void free_tokens(char** tokens){
  for(int i=0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}
