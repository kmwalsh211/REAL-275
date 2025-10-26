#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100

int findstr(char *source, char *target){
  int count = 0;
  int true = 0;
  
  for(int i = 0; i < strlen(source); i++){
    if(*(source+i) == *target){
      true = 1;
      for(int j = 0; j < strlen(target); j++){
        if(*(source+i+j) != *(target+j)){
          true = 0;
          break;
        }
      }
      if(true){
        count++;
      }
    }
  }
  
  return count;
}

int main(void){
  char source[MAXLENGTH];
  char target[MAXLENGTH];
  scanf("%s", source);
  scanf("%s", target);
  
  char *s = source;
  char *t = target;
  printf("%d\n", findstr(s, t));
  return 0;
}
