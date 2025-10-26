#include <stdio.h>

void dec2oct(unsigned int n){
  if (n <= 8){
    printf("%d%d", 0, n%8);
    return;
  }
  dec2oct((n/8));
  printf("%d", n%8);
}

int main(void){
  unsigned int x;
  scanf("%d", &x);
  dec2oct(x);
  
  printf("\n");
  return 0;
}
