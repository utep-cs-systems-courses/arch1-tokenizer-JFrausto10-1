#include <stdio.h>
#include "tokenizer.c"

int main(){
  char user_input[32];
  printf("~$");
  fgets(user_input, 32, stdin);
  char** token = tokenize(user_input);
  print_tokens(token);
  int wordCount = count_words(user_input);
  printf("Word Count is %d\n",wordCount);
  free(token);
  return 0;

}  
