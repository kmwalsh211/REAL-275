#include <stdio.h>
#include <string.h>

int ispangram(char s[]){      //A=97 Z=122
  int letters[26];
  for(int i = 0; i < strlen(s); i++){
    if (((int) s[i] <= 122) && ((int) s[i] >= 97)){
      letters[((int) s[i]) - 97] = 1;
    }
  }
  
  for(int i = 0; i < 26; i++){
    if (letters[i] != 1){
      return 0;
    }
  }
  return 1;
}

int main(void){
  char *s;
  int ch;
  int i = 0;
  while((ch = getchar()) != EOF){
    s[i] = ch;
    i++;
  }
  
  printf("%d\n", ispangram(s));
  return 0;
}
